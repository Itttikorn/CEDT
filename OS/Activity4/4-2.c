// 4.2
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

void *say_hello(void *data)
{
    char *str;
    str = (char *)data;
    printf("%s\n", str);
}

int main() {
    int pid1, pid2;

    pid1 = fork();

    if (pid1 == 0) {
        //child
        pthread_t c1, c2;
        pthread_create(&c1, NULL, say_hello, "First thread from child process");
        pthread_create(&c2, NULL, say_hello, "Second thread from child process");
        pthread_join(c1, NULL);
        pthread_join(c2, NULL);
    } else if (pid1 > 0) {
        //parent
        pthread_t p1, p2;
        pthread_create(&p1, NULL, say_hello, "First thread from parent process");
        pthread_create(&p2, NULL, say_hello, "Second thread from parent process");
        pthread_join(p1, NULL);
        pthread_join(p2, NULL);
    } else {
        printf("Error: fork failed.\n");
    }
}