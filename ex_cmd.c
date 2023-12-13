#include "main.h"

/**
* exeCmd - Executes commands,
*/

void exeCmds(char **commands)
{
    pid_t child_pid;
    int i;

    /* Iterate through the commands */
    for (i = 0; commands[i] != NULL; i++)
    {
        /* Execute the command in the child process */
        child_pid = fork();

        if (child_pid == 0)
        {
            /* This code runs in the child process */
            execve(commands[i], commands, environ);

            /* If execve fails */
            perror("execve");
            exit(EXIT_FAILURE);
        }
        else if (child_pid < 0)
        {
            perror("fork");
        }
        else
        {
            /* waits for child to finish, then runs in the parent process */
            if (waitpid(child_pid, NULL, 0) == -1)
            {
                perror("waitpid");
            }
        }
    }
}

