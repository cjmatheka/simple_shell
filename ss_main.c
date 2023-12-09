#include "main.h"

/**
* ss_main - takes arguments from user and interprets it
 * for use by the operating system
*/

int ss_main()
{
    /* Shell startup: Greet the user, clear the terminal, then start with $ sign */
    shell_init();
    _clear();
    dollar_sign();
    fflush(stdout);





    return (0);
}