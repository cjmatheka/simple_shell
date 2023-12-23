#include "main.h"

/**
* checks if command exists
*/

int cmdExists(const char *command)
{
    if (access(command, X_OK) == 0)
    {
        return (1);
    }
    return (0);
}