#include "main.h"

/**
* exeCmd - Executes commands,
 * @commands: Commands to execute,
*/

void exeCmds(char **commands)
{
    int i;

    for (i = 0; commands[i] != NULL; i++)
    {
        if (_strcmp(commands[i], "ls") == 0)
	{
            _ls(".");
        }
	else if (_strcmp(commands[i], "cd") == 0)
	{
            if (i > 1)
	    {
                _cd(commands[1]);
            } else {
                _cd(".");
            }
        }
	else if (_strcmp(commands[i], "pwd") == 0)
	{
            _pwd();
        }
	else if (_strcmp(commands[i], "clear") == 0)
	{
            clearTerminal();
        } else if (_strcmp(commands[i], "exit") == 0 || _strcmp(commands[i], "quit") == 0)
	{
            exit(0);
        }
	else
	{
            pid_t child_pid = fork();

            if (child_pid == 0)
	    {
                /* Child process */
                execve(commands[i], commands, environ);
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
                waitHelper(child_pid); /* waits for child */
            }
        }
    }
}




