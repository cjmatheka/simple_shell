#include "main.h"

/**
 * _fpath - finds command in path,
 * @command: command to find
 * @path: path to find it,
 * Return: Null.
 */

char *fpath(const char *command, const char *path)
{
	char *path_copy;
	char *dir;
	char *full_path;

	path_copy = _strdup(path);
	dir = _strtok(path_copy, ":");
	full_path = malloc(MAX_PATH_LENGTH);

	while (dir != NULL)
	{
		snprintf(full_path, MAX_PATH_LENGTH, "%s/%s", dir, command);

		if (access(full_path, X_OK) == 0)
		{
			free(path_copy);
			return (full_path);
		}

		dir = _strtok(NULL, ":");
	}

	free(path_copy);
	free(full_path);
	return (NULL);
}