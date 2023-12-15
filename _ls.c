#include "main.h"

/**
 * _ls - handles the ls command
 * @path: path to directory
 */

void _ls(const char *path)
{
	DIR *dir;
	struct dirent *entry;

	dir = opendir(path);
	if (dir == NULL)
	{
		perror("opendir");
		return;
	}

	while ((entry = readdir(dir)) != NULL)
	{
		if (entry->d_name[0] != '.')
		{
			write(STDOUT_FILENO, entry->d_name, strlen(entry->d_name));
			write(STDOUT_FILENO, " ", 1);
		}
	}
	closedir(dir);
	write(STDOUT_FILENO, "\n", 1);
}
