#include "main.h"

/**
 * waitHelper - helps wait for child process to end,
 * then allows parent process to take over.
 * @child_pid: Child process.
 */

void waitHelper(pid_t child_pid)
{
	if (waitpid(child_pid, NULL, 0) == -1)
	{
		perror("waitpid");
	}
}
