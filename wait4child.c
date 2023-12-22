#include "main.h"

/**
 * wait4child - parent waits for child
 */

void wait4child()
{
    int status;
    pid_t child_pid;

    while ((child_pid = wait(&status)) > 0)
    {
        if (WIFEXITED(status))
	{
            printf("Child process %d exited with status %d\n", child_pid, WEXITSTATUS(status));
        }
	else
	{
            printf("Child process %d exited abnormally\n", child_pid);
        }
    }
}