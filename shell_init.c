#include "main.h"

/**
* shell_init - this initializes the shell, providing the name and username,
*/

void shell_init()
{
    _clear();

    /* Declare variables to use in this function */
    char *username;
    time_t current_time;
    struct tm *local_time;

    _printstr("\n\n\n\n******************"
           "************************");
    _printstr("\n\n\n\t****A VERY SIMPLE SHELL****");
    _printstr("\n\n\t- CREATED BY JULIUS AND RUTH \n USE AS YOU MAY -");
    _printstr("\n\n\n\n*******************"
           "***********************");

    /* Retrieve the username using getenv("USER") */
    username = getenv("USER");
    write(STDOUT_FILENO, "\n\n\nUSER is: @", 13);
    write(STDOUT_FILENO, username, _strlen(username));
    write(STDOUT_FILENO, "\n", 1);

    /* Pause for 1 second */
    sleep(1);

    _clear();
}