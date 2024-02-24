#include "main.h"

/**
 * _strcmp - compares a string to another,
 * @s1: First string,
 * @s2: second string,
 * Return: 0 on Success.
 */

int _strcmp(const char *s1, const char *s2)
{
	while (*s1 != '\0' && *s2 != '\0' && *s1 == *s2)
	{
		s1++;
		s2++;
	}
	return (*s1 - *s2);
}
