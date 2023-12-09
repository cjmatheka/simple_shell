#include "main.h"

/**
 * _putchar - prints a character to stdout,
 * @c: The character to be printed out,
 * Return: 0 on success, -1 on failure.
 */

int _putchar(char c)
{
    if (write(1, &c, 1) == -1)
    {
        return (-1);
    }

    return (1);
}