#include "main.h"

/**
 * _pwd - prints current working directory,
 */

void _pwd()
{
    pid_t child_pid = fork();
    char *cmd;
    char *args[] = {NULL, NULL};

    if (child_pid == 0)
    {
        /* Child process */
        cmd = "/usr/bin/pwd";
        args[0] = cmd;

        execve(cmd, args, environ);
        perror("execve"); /* If execve fails */
        exit(EXIT_FAILURE);
    }
    else if (child_pid < 0)
    {
        perror("fork");
    }
    else
    {
        /* Parent process */
        waitpid(child_pid, NULL, 0); /* waits for child */
    }
}
