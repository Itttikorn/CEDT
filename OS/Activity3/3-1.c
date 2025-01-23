// 3.1
#include<stdio.h>
#include<unistd.h>

int main() {
    int pid1, pid2;

    pid1 = fork();

    if (pid1 == 0) {
        printf("I am the child process. My PID is %d and my parent's PID is %d\n", getpid(), getppid());
        pid2 = fork();
        if (pid2 == 0) {
            printf("I am the Grandchild Process. My PID is %d and my parent's PID is %d\n", getpid(), getppid());
        }
    } else if (pid1 > 0) {
        printf("I am the parent process. My PID is %d\n", getpid());
    } else {
        printf("Error: fork failed.\n");
    }
}