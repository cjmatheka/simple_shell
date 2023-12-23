#include "main.h"

/**
 * _strtok - tokenizes a line of commands
 * @str: the line to tokenize,
 * @delimiters: where to separate them
 * Return: first command.
 */

char *_strtok(char *str, const char *delimiters)
{
	static char *token;
	char *start;

	token = (NULL);

	/* If str is not NULL, set the token to the beginning of the string */
	if (str != NULL)
		token = str;
	else if (token == NULL)
		return (NULL);

	/* Find the beginning of the next token (skip leading delimiters) */
	while (*token != '\0' && strchr(delimiters, *token) != NULL)
		token++;

	/* If we've reached the end of the string, return NULL */
	if (*token == '\0')
		return (NULL);

	/* Save the start of the token */
	start = token;

	/* Find the end of the token (find the next delimiter) */
	while (*token != '\0' && strchr(delimiters, *token) == NULL)
		token++;

	/* replace the delimiter with null character if not end */
	if (*token != '\0')
	{
		*token = '\0';
		token++;
	}
	return (start);
}
