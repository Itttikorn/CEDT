//4-1
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
void *say_hello(void *data)
{
    char *str;
    str = (char *)data;
    while (1)
    {
        printf("This is thread %s\n", str);
        sleep(1);
    }
}
void main(int argc, char *argv[])
{
    pthread_t t1, t2;
    if (argc < 3) {
        printf("usage : thread_sol1 arg1 arg2 \n");
        exit(1);
    }
    pthread_create(&t1, NULL, say_hello, argv[1]);
    pthread_create(&t2, NULL, say_hello, argv[2]);
    pthread_join(t1, NULL);
    pthread_join(t2, NULL);
}