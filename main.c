#include "main.h"

/**
* ss_main - takes arguments from user and interprets it
 * for use by the operating system
*/

int ss_main()
{
    /* Declare variables to use in the program */
    ssize_t read;
    char *line = NULL;
    size_t len = 0;
    pid_t pid;
    char *token;

    while (1)
    {
        /* Shell startup: Greet the user, then clear the terminal */
        shell_init();
        _clear();

        /* Start by printing $ sign into stdout */
        dollar_sign();
        fflush(stdout);

        /* Deal with user input - Use getline to read a line from stdin */
        read = getline(&line, &len, stdin);

        if (read != -1)
        {
            /* Process the user input (in this case, just printing it) */
            /**
             * tokenization,
             *
             */
            printf("You entered: %s", line);
        }
        else
        {
            perror("getline");
        }
        command = pwd;
        if (command != '\0')
        {
            pid = fork()
                    // call getcwd () function to achieve what the user requested
        }

        /* Free the dynamically allocated memory */
        free(line);

        return (0);
    }
}