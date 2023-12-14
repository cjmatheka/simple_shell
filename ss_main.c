#include "main.h"

/**
* main - takes arguments from user and interprets it
 * for use by the operating system
*/

int main()
{
    int i;
    char** commands, *line;
    size_t len;
    ssize_t read;

    /* Shell startup */
    shell_init();

    while (1)
    {
        /* Print $ */
        dollar_sign();
        fflush(stdout);

        /* Deal with user input */
        line = NULL;
        len = 0;
        read = getline(&line, &len, stdin);

        if (read != -1)
        {
            /* Process the user input */
            line[_strcspn(line, "\n")] = '\0';
            commands = processInput(line);

            /* Check if commands have been added */
            if (commands == NULL)
            {
                break;
            }

            /* Execute the commands */
            exeCmds(commands);

            /* Free the memory for commands */
            for (i = 0; commands[i] != NULL; i++)
            {
                free(commands[i]);
            }
            free(commands);
        }
        else
        {
            perror("getline");
        }

        /* Free dynamically allocated memory */
        free(line);
    }

    /* This point is reached only when the user wants to exit the shell */
    return 0;
}