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
			/* Remove newline character */
			line[strcspn(line, "\n")] = '\0';

			tokens = tokenizeInput(line);
			if (tokens != NULL)
			{
				executeCommands(tokens);
			}
			else
			{
				perror("No command found");
			}
		}
		else
		{
			write(STDOUT_FILENO, "\nExiting Shell\n", 15);
			continue;
		}
		free(line);
	}
	return (0);
}

