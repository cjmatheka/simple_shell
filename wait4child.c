#include "main.h"

/**
 * wait4child - parent waits for child
 */

void wait4child(void)
{
	int status;
	pid_t child_pid;

	while ((child_pid = wait(&status)) > 0)
	{
		return;
		/* Do not print anything */
	}
}
