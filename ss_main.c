#include "main.h"

/**
* main - takes arguments from user and interprets it
 * for use by the operating system
 * Return: ) on success.
*/

int main(void)
{

	char *line, **tokens = NULL;
	size_t len;
	ssize_t read;

	shell_init();

	while (1)
	{
		dollar_sign();
		fflush(stdout);

		line = NULL;
		len = 0;
		read = getline(&line, &len, stdin);

		if (read != -1)
		{
			tokens = tokenizeInput(line);
			if (tokens != NULL)
			{
				executeCommands(tokens);
				exit(EXIT_SUCCESS);
			}
			else
			{
				perror("No command found");
				exit(EXIT_FAILURE);
			}
		}
		else
		{
			write(STDOUT_FILENO, "\nExiting Shell\n", 15);
			break;
		}

		free(line);
	}

	return (0);
}

