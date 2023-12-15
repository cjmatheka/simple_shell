#include "main.h"

/**
 * _cd - changes directory to specified path,
 * @path: Path to change directory to.
 */

void _cd(const char *path)
{
	if (chdir(path) != 0)
	{
		perror("cd");
	}
}
