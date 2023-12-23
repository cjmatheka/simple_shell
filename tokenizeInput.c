#include "main.h"

/**
 * tokenizeInput - processes user input,
 * @line: input to process
 * Return: tokens
 */

char **tokenizeInput(char *line)
{
	char *token, **tokens;
	int count;

	/* Tokenize input */
	token = _strtok(line, " ");


	if (token == NULL)
	{
		return (NULL);
	}

	tokens = malloc(sizeof(char *) * MAX_TOKENS);

	if (tokens == NULL)
	{
		perror("Unable to allocate memory");
		exit(EXIT_FAILURE);
	}

	/* Copy tokens to array */
	do {
		count = 0;

		tokens[count] = _strdup(token);
		count++;

		token = _strtok(NULL, " ");
	} while (token != NULL && count < MAX_TOKENS - 1);

	/* Add a NULL pointer at the end to indicate the end of the array */
	tokens[count] = NULL;

	return (tokens);
}
