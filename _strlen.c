#include "main.h"

/**
* _strlen - returns the length of a string,
 * @str: pointer to the string,
 * Return: string length,
*/

size_t _strlen(const char *str)
{
	size_t len;

	len = 0;

	while (str[len] != '\0')
	{
		len++;
	}
	return (len);
}
