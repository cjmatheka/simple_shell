#include "main.h"

/**
 * _strncmp - copies size n of S2 to S1,
 * @s1: destination string,
 * @s2: source string,
 * @n: Length of S2 to copy to S1,
 * Return: ) on success
 */

int _strncmp(const char *s1, const char *s2, size_t n)
{
    /* declare variables to be used */
    size_t i;

    /* iterate through the strings and copy */
    for (i = 0; i < n && (s1[i] != '\0' || s2[i] != '\0'); i++)
    {
        if (s1[i] != s2[i])
        {
            return ((s1[i] < s2[i]) ? -1 : 1);
        }
    }
    /* Return 0 if both are equal */
    return (0);
}