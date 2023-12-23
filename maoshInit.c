#include "main.h"

/**
* shell_init - this initializes the shell, providing the name and username,
*/

void shell_init(void)
{
	char *username;

	_clear(); /* Clear terminal */

	username = _getenv("USER"); /*retrieve user information*/
	if (username != NULL)
	{
		write(STDOUT_FILENO, username, _strlen(username));
		write(STDOUT_FILENO, "\n", 1);
	}

	/* Pause for 1 second then clear terminal */
	sleep(1);
	_clear();
}


/**
* dollar_sign - prints the dollar sign to stdout,
 * Return: 0 on success.
*/

int dollar_sign(void)
{
	/* Declare the prompt for holding the $ sign for printing to out put */
	char prompt, *username;

	/* initialize the prompt to hold the dollar sign */
	prompt = '$';
	username = _getenv("USER");


	/* print the username and $ sign to standard output */
	write(STDOUT_FILENO, username, _strlen(username));
	write(STDOUT_FILENO, "@maossh", 7);
	write(STDOUT_FILENO, &prompt, 1);
	write(STDOUT_FILENO, " ", 1);

	/* return 0 on success */
	return (0);
}
