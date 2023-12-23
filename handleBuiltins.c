#include "main.h"

/**
* executeBuiltins - handles builtin functions
*/

void handleBuiltins(char *line)
{
	int status;

	status = system(line);

	if (status == -1)
	{
        perror("system");
        exit(EXIT_FAILURE);
    }
}