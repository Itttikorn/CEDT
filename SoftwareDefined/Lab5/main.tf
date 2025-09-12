terraform {
    required_providers {
        docker = {
        source  = "kreuzwerker/docker"
        version = "~> 2.21.0"
        }
    }
}

provider "docker" {}

resource "docker_image" "todo-service" {
    name         = "natawut/todo-service:release-3"
    keep_locally = false
}

resource "docker_image" "redis" {
    name         = "redis:latest"
    keep_locally = false
}

resource "docker_image" "todo-notification" {
    name         = "todo-notification"
    keep_locally = false
    build {
        path    = "${path.module}/todo-notification"
        dockerfile = "Dockerfile"
    }
}

resource "docker_network" "todo_net" {
    name = "todo_net"
}

resource "docker_container" "todo-service" {
    image = docker_image.todo-service.image_id
    name  = "todo-service"
    env = [
        "REDIS_HOST=redis",
        "REDIS_PORT=6379",
        "NOTIFICATION_HOST=todo-notification",
        "NOTIFICATION_PORT=9000"
    ]
    ports {
        internal = 8000
        external = 8000
    }
    networks_advanced {
        name = docker_network.todo_net.name
    }
    depends_on = [docker_container.redis]
}

resource "docker_container" "redis" {
    image = docker_image.redis.image_id
    name  = "redis"
    ports {
        internal = 6379
        external = 6379
    }
    networks_advanced {
        name = docker_network.todo_net.name
    }
}

resource "docker_container" "todo-notification" {
    image = docker_image.todo-notification.image_id
    name  = "todo-notification"
    ports {
        internal = 9000
        external = 9000
    }
    networks_advanced {
        name = docker_network.todo_net.name
    }
    depends_on = [docker_container.todo-service]
}
