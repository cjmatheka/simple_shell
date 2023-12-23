#include "main.h"

/**
* handleExternals - Executes commands,
 * @tokens: Commands to execute,
*/

void handleExternals(char **tokens)
{
	pid_t child_pid;
	char *path, *path_copy, *dir, *full_path;

	child_pid = fork();

	if (child_pid == 0)
	{
		/* Child process */
		if (execvp(tokens[0], tokens) == -1)
		{
			perror("Could not run command");
		}

		/* If execvp fails, the command might not be in the current directory. */
		/* Try appending the command to each directory in the PATH. */
		path = _getenv("PATH");
		path_copy = _strdup(path);
		dir = _strtok(path_copy, ":");

		while (dir != NULL)
		{
			full_path = malloc(_strlen(dir) + _strlen(tokens[0]) + 2);

			if (full_path == NULL)
			{
				perror("Could not allocate memory");
				exit(EXIT_FAILURE);
			}
			strcpy(full_path, dir);
			strcat(full_path, "/");
			strcat(full_path, tokens[0]);

			if (execvp(full_path, tokens) != -1)
			{
				free(path_copy);
				free(full_path);
				exit(EXIT_SUCCESS);
			}
			free(full_path);
			dir = _strtok(NULL, ":");
		}
	}
	else if (child_pid < 0)
	{
		perror("Process not created");
	}
	else
	{
		/* Parent process waits for the child */
		wait4child();
	}
}



