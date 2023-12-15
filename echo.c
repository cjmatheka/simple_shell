#include "main.h"

/**
 * _echoPrint - prints message to stdout
 * @msg: message to print.
 */

void _echoPrint(const char *msg)
{
	size_t len = _strlen(msg);

	/* Using the write system call to display the message */
	if (write(STDOUT_FILENO, msg, len) != (ssize_t)len)
	{
		/* If there was an error in writing, you can handle it here */
		perror("Unable to print");
	}
}
