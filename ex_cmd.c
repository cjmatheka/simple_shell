#include "main.h"

/**
* exeCmd - Executes commands,
 * @commands: Commands to execute,
*/

void exeCmds(char **commands)
{
	pid_t child_pid;
	int i;

	for (i = 0; commands[i] != NULL; i++)
	{
		child_pid = fork();

		if (child_pid == 0)
		{
			/* This code runs in the child process */
			if (_strcmp(commands[i], "ls") == 0)
			{
				_ls(".");
			}
			else if (_strcmp(commands[i], "pwd") == 0)
			{
				_pwd();
			}
			else if (_strcmp(commands[i], "clear") == 0)
			{
				clearTerminal();
			}
			else if (_strcmp(commands[i], "exit") == 0)
			{
				_exitShell(0);
			}
			else
			{
				execve(commands[i], commands, environ);
				perror("execve"); /* If execve fails */
				exit(EXIT_FAILURE);  /* Exit child process if execve fails */
			}
		}
		else if (child_pid < 0)
		{
			perror("fork");
		}
		else
		{
			waitHelper(child_pid); /* waits for child, runs in the parent process */
		}
	}
}




