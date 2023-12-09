#include "main.h"

/**
* dollar_sign - prints the dollar sign to stdout,
 * Return: 0 on success.
*/

int dollar_sign()
{
    /* Declare the prompt for holding the $ sign for printing to out put */
    char prompt;

    /* initialize the prompt to hold the dollar sign */
    prompt = '$';

    /* print the $ sign to standard output */
    write(STDOUT_FILENO, &prompt, 1);

    /* return 0 on success */
    return (0);
}