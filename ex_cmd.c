#include "main.h"

/**
* exeCmd - Executes commands,
 * @commands: Commands to execute,
*/

void exeCmds(char **commands)
{
	int j, i;
	char *path;

	path = (char *)malloc(MAX_LENGTH);
	if (path == NULL)
	{
		perror("malloc");
		exit(EXIT_FAILURE);
	}

	for (i = 0; commands[i] != NULL; i++)
	{
		if (_strcmp(commands[i], "ls") == 0)
		{
			if (commands[i + 1] != NULL)
			{
				_strcpy(path, commands[i + 1]);
				_ls(path);
				/* Skip the next argument since it's the path */
				i++;
			} else
			{
				/* Use current directory if no path is provided */
				_ls(".");
			}
		}
		else if (_strcmp(commands[i], "echo") == 0)
		{
			for (j = i + 1; commands[j] != NULL; j++)
			{
				write(STDOUT_FILENO, commands[j], strlen(commands[j]));
				if (commands[j + 1] != NULL)
				{
					write(STDOUT_FILENO, " ", 1);
				}
			}
			write(STDOUT_FILENO, "\n", 1);
		}
		else if (strcmp(commands[i], "cd") == 0)
		{
			if (commands[i + 1] != NULL)
			{
				_strcpy(path, commands[i + 1]);
				_cd(path);
				/* Skip the next argument since it's the path */
				i++;
			}
			else
			{
				_cd(".");
			}
		}
		else if (strcmp(commands[i], "pwd") == 0)
		{
			_pwd();
		}
		else if (strcmp(commands[i], "env") == 0)
		{
			_env();
		}
		else if (strcmp(commands[i], "clear") == 0)
		{
			clearTerminal();
		}
		else if (strcmp(commands[i], "exit") == 0 || strcmp(commands[i], "quit") == 0)
		{
			free(path); /* Release allocated memory */
			exit(0);
		}
		else
		{
			pid_t child_pid = fork();

			if (child_pid == 0)
			{
				/* Child process */
				execvp(commands[i], commands);
				/* If execvp fails */
				perror("execvp");
				exit(EXIT_FAILURE);
			}
			else if (child_pid < 0)
			{
				perror("fork");
			}
			else
			{
				/* Parent process waits for child process */
				waitpid(child_pid, NULL, 0);
			}
		}
	}
	/* Release allocated memory */
	free(path);
}




