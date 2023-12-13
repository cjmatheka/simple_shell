#include "main.h"

/**
* exeCmd - Executes commands,
*/

void exeCmds(char **commands)
{
    char *token;
    const char delimiter[2] = " ";
    int i;
    pid_t child_pid;
    char *argv[MAX_ARGS];
    int argCount;

    /* Iterate through the commands */
    for (i = 0; commands[i] != NULL; i++)
    {
        token = strtok(commands[i], delimiter);

        while (token != NULL)
        {
            /* Execute each token (command) in the child process */
            child_pid = fork();

            if (child_pid == 0)
            {
                argCount = 0;

                /* Split the command into an array of arguments */
                do
                {
                    argv[argCount++] = token;
                    token = strtok(NULL, delimiter);
                } while (token != NULL && argCount < MAX_ARGS - 1);

                argv[argCount] = NULL;

                /* This code runs in the child process */
                execve(argv[0], argv, environ);

                /* If execlp fails */
                perror("execve");
                exit(EXIT_FAILURE);
            }
            else if (child_pid < 0)
            {
                perror("fork");
            }
            else
            {
                /* waits for child to finish, then runs in parent process */
                waitpid(child_pid, NULL, 0);
            }
            token = strtok(NULL, delimiter);
        }
    }
}
