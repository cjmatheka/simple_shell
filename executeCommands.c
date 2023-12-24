#include "main.h"

/**
 * executeCommands - exeute commands
 * @line: commands
 */

void executeCommands(char *line)
{
	char **tokens;
	int i;

	/* Tokenize input */
	tokens = tokenizeInput(line);

	if (tokens == NULL)
	{
		return;
	}
	/* Check if it's a built-in command and use system */
	if (_strcmp(tokens[0], "pwd") == 0 || _strcmp(tokens[0], "cd") == 0
	|| _strcmp(tokens[0], "clear") == 0 || _strcmp(tokens[0], "env") == 0 )
	{
		handleBuiltins(tokens);
	}
	else if (_strcmp(tokens[0], "/bin/ls") == 0)
	{
		system("ls");
	}
	else if (_strcmp(tokens[0], "exit") == 0)
	{
		exit(EXIT_SUCCESS);
	}
	/* Free memory allocated for tokens */
	for (i = 0; tokens[i] != NULL; i++)
	{
		free(tokens[i]);
	}
	free(tokens);
}

