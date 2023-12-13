#include "main.h"

/**
 * _strcpy - Copies a string,
 * @dest: destination,
 * @src: Source,
 */

void _strcpy(char *dest, const char *src)
{
    /* Iterate through the source string and copy each character to the destination */
    while (*src != '\0')
    {
        *dest = *src;
        dest++;
        src++;
    }

    /* Add the null terminator at the end of the destination string */
    *dest = '\0';
}
