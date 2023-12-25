#include "main.h"

/**
 * listItems - lists items in a directory,
 * @dir: directory to list items from.
 */

void listItems(const char *dir)
{
	/* declare variables */
	const char *name;
	struct dirent *entry;
	DIR *dp;

	/* Open the directory */
	dp = opendir(dir);

	if (dp == NULL)
	{
		perror("Error opening directory");
		return;
	}

	/* Read directory entries */
	while ((entry = readdir(dp)) != NULL)
	{
		/* Extract file/directory name from the entry */
		name = entry->d_name;

		/* Skip the special entries "." and ".." */
		if (strcmp(name, ".") == 0 || strcmp(name, "..") == 0)
		{
			continue;
		}

		/* Print the name */
		printf("%s\n", name);
	}

	/* Close the directory */
	closedir(dp);
}