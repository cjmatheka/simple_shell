#include "main.h"

/**
 * _strcspn - returns the length of characters not specified,
 * @str: The characters specified,
 * @reject: The characters no specified,
 * Return: count of rejected characters.
 */

size_t _strcspn(const char *str, const char *reject)
{
	const char *s;
	size_t count;

	count = 0;

	while (*str)
	{
		for (s = reject; *s; s++)
		{
			if (*str == *s)
			{
				return (count);
			}
		}
		str++;
		count++;
	}
	return (count);
}
