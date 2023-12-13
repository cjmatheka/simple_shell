#include "main.h"

/**
* exeCmd - Executes commands,
 * @commands: Commands to execute,
*/

void exeCmds(char **commands) {
    pid_t child_pid;
    int i;

    for (i = 0; commands[i] != NULL; i++)
    {
        child_pid = fork();

        if (child_pid == 0)
        {
            /* This code runs in the child process */

            /* Check for specific commands and call corresponding functions */
            if (_strcmp(commands[i], "ls") == 0)
            {
                _ls(".");
                exit(EXIT_SUCCESS);
            }
            else if (_strcmp(commands[i], "pwd") == 0)
            {
                _pwd();
                exit(EXIT_SUCCESS);
            }
            else if (_strcmp(commands[i], "clear") == 0)
            {
                clearTerminal();
                exit(EXIT_SUCCESS);
            }
            else if (_strcmp(commands[i], "exit") == 0)
            {
                exitTerminal();
                exit(EXIT_SUCCESS);
            }
            else
            {
                execve(commands[i], commands, environ);
                /* If execve fails */
                perror("execve");
                exit(EXIT_FAILURE);
            }

            /* If not a custom command, execute it using execve */
            execve(commands[i], commands, environ);

            /* If execve fails */
            perror("execve");
            exit(EXIT_FAILURE);
        }
        else if (child_pid < 0)
        {
            perror("fork");
        } else
        {
            /* waits for child to finish, then runs in the parent process */
            if (waitpid(child_pid, NULL, 0) == -1)
            {
                perror("waitpid");
            }
        }
    }
}

