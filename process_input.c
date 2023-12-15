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

	/*Remove the newline character et the end, tokenize, then allocate memory */
	line[_strcspn(line, "\n")] = '\0';
	token = strtok(line, " ");
	if (token == NULL)
	{
		return (NULL);
	}
	tokens = malloc(sizeof(char *));
	if (tokens == NULL)
	{
		perror("malloc");
		exit(EXIT_FAILURE);
	}
	/* Copy the first token (command) to the array, then the rest */
	tokens[0] = strdup(token);
	count = 1;
	while ((token = strtok(NULL, " ")) != NULL)
	{
		tokens = realloc(tokens, (count + 1) * sizeof(char *));
		if (tokens == NULL)
		{
			perror("realloc");
			exit(EXIT_FAILURE);
		}
		tokens[count] = strdup(token);
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
