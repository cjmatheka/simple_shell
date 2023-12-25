#include "main.h"

/**
 * executeCommands - exeute commands
 * @line: commands
 */

void executeCommands(char **tokens)
{
	pid_t child_pid;
	char bin_path[256];

	child_pid = fork();

	if (child_pid == -1)
	{
		perror("Could not create a child process");
		exit(EXIT_FAILURE);
	}
	else if (child_pid == 0)
	{
		if (_strcmp(tokens[0], "ls") == 0)
		{
			 /* Construct the full path to the executable in the /bin directory */
			snprintf(bin_path, sizeof(bin_path), "/bin/listItems.sh");

			/* Execute the command using execve */
			execve(bin_path, tokens, environ);

			/* If execve fails */
			perror("Execution failed");
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		wait4child();
	}
}

