#include "main.h"

/**
 * _printstr - prints a string to stdout,
 * @str: the string to be printed,
 * Return: Nothing.
 */

void _printstr(const char *str)
{
    while (*str != '\0') {
        _putchar(*str);
        str++;
    }
}