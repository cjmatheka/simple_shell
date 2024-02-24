#include "main.h"

/**
 * _strdup - duplicates a string,
 * @str1: string to duplicate,
 * Return: Duplicated string.
 */

char *_strdup(const char *str1)
{
	size_t len;
	char *str2;

	if (str1 == NULL)
	{
		return (NULL);
	}

	/* calculate length of string */
	len = _strlen(str1);
	str2 = (char *) malloc((len + 1) * sizeof(char));

	if (str2 != NULL)
	{
		_strcpy(str2, str1);
	}
	return (str2);
}

/**
 * free_string - frees string space
 * @str1: string to free,
 */

void free_string(char *str1)
{
	free(str1);
}

