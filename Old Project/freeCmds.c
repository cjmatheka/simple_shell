#include "main.h"

/**
* freeCmds - free commands
 * @commands: pointer to an array of pointers to free,
 * Return: ) on Success.
*/

int freeCmds(char **commands)
{
	int i;

	for (i = 0; commands[i] != NULL; i++)
	{
		free(commands[i]);
	}
	return (0);
}
