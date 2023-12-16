#include "main.h"

/**
* main - takes arguments from user and interprets it
 * for use by the operating system
 * Return: ) on success.
*/

int main(int argc, char **argv)
{
	char **commands, *line;
	size_t len;
	ssize_t read;

	/* declaring void variables */
	(void)argc; (void)argv;

	/* Shell startup and use */
	shell_init();
	while (1)
	{
		/* Print $ */
		dollar_sign();
		fflush(stdout);

		/* Deal with user input */
		line = NULL, len = 0, read = getline(&line, &len, stdin);

		if (read != -1)
		{
			/* Process the user input */
			line[_strcspn(line, "\n")] = '\0';
			commands = processInput(line);

			/* Check if commands have been added */
			if (commands == NULL)
			{
				break;
			}
			/* Execute the commands then free memory */
			exeCmds(commands);
			freeCmds(commands);
			free(commands);
		}
		else
		{
			write(STDOUT_FILENO, "\n", 1);
			return (-1);
		}
		free(line);
	}
	return (0);
}
