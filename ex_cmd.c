#include "main.h"

/**
* exeCmd - Executes commands,
 * @commands: Commands to execute,
*/

void exeCmds(char **commands)
{
	int j, i;
	char *path;
	const char *options = NULL;
	const char *filename;

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
				_ls(path, options);
				/* Skip the next argument since it's the path */
				i++;
			} else
			{
				/* Use current directory if no path is provided */
				_ls(".", options);
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
		else if (strcmp(commands[i], "cat") == 0)
		{
			if (commands[i + 1] != NULL)
			{
				filename = commands[i + 1];
				_cat(filename);
				/* Skip the next argument since it's the filename */
				i++;
			}
			else
			{
				write(STDERR_FILENO, "File error", 11);
			}
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
				execve(commands[i], commands, NULL);
				/* If execvp fails */
				perror("execve");
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




