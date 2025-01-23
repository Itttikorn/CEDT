#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
int main(int argc, char *argv[])
{
    pid_t pid;
    if (argc < 2) {
        printf("Please enter UNIX command.\n");
        exit(1);
    }
    char *av[argc];
    for (int i = 0; i < argc - 1; i++) {
        av[i] = argv[i + 1];
    }
    av[argc - 1] = NULL;
    pid = fork();
    if (pid < 0)
    {
        printf("Error : cannot fork\n");
        exit(1);
    }
    else if (pid == 0)
    {
        execvp(argv[1], av);
        printf("Error: exec failed\n");
        exit(1);
    }
    else
    {
        wait(NULL);
        return (0);
    }
}