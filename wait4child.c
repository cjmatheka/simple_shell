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
        /* Do not print anything */
    }
}