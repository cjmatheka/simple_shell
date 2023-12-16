#include "main.h"

/**
 * _env - prints current environment.
 */

void _env()
{
    char **env_ptr;
    ssize_t len;

    env_ptr = environ;

    while (*env_ptr != NULL)
    {
        len = _strlen(*env_ptr);
        write(STDOUT_FILENO, *env_ptr, len);
        write(STDOUT_FILENO, "\n", 1);
        env_ptr++;
    }
}