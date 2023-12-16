#include "main.h"

/**
 * _ls - handles the ls command
 * @path: path to directory
 */

void _ls(const char *path, const char *options)
{
    pid_t child_pid = fork();
    char *cmd;
    char *args[] = {"ls", NULL, NULL, NULL, NULL};

    if (child_pid == 0)
    {
        /* Child process */
        cmd = "/usr/bin/ls";
        args[1] = (char *)path;

	if (options != NULL)
	{
            args[2] = (char *)options;
        }

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

