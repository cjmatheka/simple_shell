#include "main.h"

/**
* processInput - processes user input,
 * @line: line to process,
 * Return: Token,
*/

char **processInput(char *line)
{
	char *token, **tokens;
	int count;

	/*Remove the newline character at the end, tokenize, then allocate memory */
	line[_strcspn(line, "\n")] = '\0';
	token = _strtok(line, " ");
	if (token == NULL)
	{
		return (NULL);
	}
	tokens = malloc(sizeof(char *));
	if (tokens == NULL)
	{
		perror("Unable to allocate memory");
		exit(EXIT_FAILURE);
	}
	/* Copy the first token (command) to the array, then the rest */
	tokens[0] = _strdup(token);
	count = 1;
	while ((token = _strtok(NULL, " ")) != NULL)
	{
		tokens = realloc(tokens, (count + 1) * sizeof(char *));
		if (tokens == NULL)
		{
			perror("realloc");
			exit(EXIT_FAILURE);
		}
		tokens[count] = _strdup(token);
		count++;
	}
	/* Add a NULL pointer at the end to indicate the end of the array */
	tokens = realloc(tokens, (count + 1) * sizeof(char *));
	if (tokens == NULL)
	{
		perror("realloc");
		exit(EXIT_FAILURE);
	}
	tokens[count] = NULL;
	return (tokens);
}
