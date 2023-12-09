#include "main.h"

/**
* ss_main - takes arguments from user and interprets it
 * for use by the operating system
*/

int ss_main()
{
    /* Clear the terminal screen */
    _clear();

    /* printing the $ sign */
    dollar_sign();

    /* ensure the prompt is clearly visible */
    fflush(stdout);

    return (0);
}