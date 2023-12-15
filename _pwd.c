#include "main.h"

/**
 * _pwd - prints current working directory,
 */

void _pwd(void)
{
	char cwd[1024];

	if (getcwd(cwd, sizeof(cwd)) != NULL)
	{
		write(STDOUT_FILENO, cwd, strlen(cwd));
		write(STDOUT_FILENO, "\n", 1);
	}
	else
	{
		perror("_pwd");
	}
}
