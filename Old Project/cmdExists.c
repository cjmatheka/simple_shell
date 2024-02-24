#include "main.h"

/**
* cmdExists - checks if command exists,
 * @command: command to be checked,
 * Return: 1 on success, 0 on fail.
*/

int cmdExists(const char *command)
{
	if (access(command, X_OK) == 0)
	{
		return (1);
	}
	return (0);
}
