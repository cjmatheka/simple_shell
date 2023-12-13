#include "main.h"

/**
* dollar_sign - prints the dollar sign to stdout,
 * Return: 0 on success.
*/

int dollar_sign()
{
    /* Declare the prompt for holding the $ sign for printing to out put */
    char prompt;
    char *username;

    /* initialize the prompt to hold the dollar sign */
    prompt = '#';
    username = _getenv("USER");

    /* print the username and $ sign to standard output */
    write(STDOUT_FILENO, username, _strlen(username));
    write(STDOUT_FILENO, &prompt, 1);
    write(STDOUT_FILENO, " ", 1);

    /* return 0 on success */
    return (0);
}