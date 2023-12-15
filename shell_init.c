#include "main.h"

/**
* shell_init - this initializes the shell, providing the name and username,
*/

void shell_init(void)
{
	char *username, user_input[256];
	ssize_t input_read;

	/* Clear terminal */
	_clear();
	/* Step 1: Print information about the shell */
	_printstr("\n\n\n\n******************************************");
	_printstr("\n\n\n\t****A VERY SIMPLE SHELL****");
	_printstr("\n\n\t- CREATED BY JULIUS AND RUTH, USE AS YOU MAY");
	_printstr("\n\n\n\n******************************************");

	/* Step 2: Retrieve the username using getenv("USER") */
	username = _getenv("USER");
	if (username != NULL)
	{
		write(STDOUT_FILENO, "\n\n\nUSER is: @", 13);
		write(STDOUT_FILENO, username, _strlen(username));
		write(STDOUT_FILENO, "\n", 1);
	}
	else
	{
		/* Prompt the user for a username */
		write(STDOUT_FILENO, "\n\n\nEnter your username: ", 24);
		input_read = read(STDIN_FILENO, user_input, sizeof(user_input) - 1);
		if (input_read > 0)
		{
			user_input[input_read - 1] = '\0';
			username = _strdup(user_input);
			if (username != NULL)
			{
				write(STDOUT_FILENO, "\n\n\nUSER is: @", 13);
				write(STDOUT_FILENO, username, _strlen(username));
				write(STDOUT_FILENO, "\n", 1);
			}
			else
			{
				write(STDOUT_FILENO, "\n\n\nUnable to allocate memory for username.\n", 43);
			}
		}
		else
		{
			write(STDOUT_FILENO, "\n\n\nError reading username.\n", 28);
		}
	}
	/* Pause for 1 second then clear terminal */
	sleep(1);
	_clear();
}
