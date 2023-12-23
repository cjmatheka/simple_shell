#include "main.h"

/**
* exeCmd - Executes commands,
 * @commands: Commands to execute,
*/

void executeCommands(char *line)
{
    char *token, **tokens;
    int i, count = 0;

    /* Tokenize input */
    token = _strtok(line, " ");
    if (token == NULL)
    {
        return;
    }

    tokens = malloc(sizeof(char *));
    if (tokens == NULL)
    {
        perror("Unable to allocate memory");
        exit(EXIT_FAILURE);
    }

    /* Copy tokens to array */
    do {
        tokens = realloc(tokens, (count + 1) * sizeof(char *));
        if (tokens == NULL)
	{
            perror("realloc");
            exit(EXIT_FAILURE);
        }
        tokens[count] = _strdup(token);
        count++;

        token = _strtok(NULL, " ");
    } while (token != NULL);

    /* Add a NULL pointer at the end to indicate the end of the array */
    tokens = realloc(tokens, (count + 1) * sizeof(char *));
    if (tokens == NULL)
    {
        perror("realloc");
        exit(EXIT_FAILURE);
    }
    tokens[count] = NULL;

    /* Check if it's a built-in command and use system */
    if (_strcmp(tokens[0], "cd") == 0 || _strcmp(tokens[0], "pwd") == 0 || _strcmp(tokens[0], "clear") == 0 || _strcmp(tokens[0], "env") == 0)
    {
        int status = system(line);
        if (status == -1)
	{
            perror("system");
            exit(EXIT_FAILURE);
        }
    }
    else if (_strcmp(tokens[0], "exit") == 0)
    {
	    exit(EXIT_SUCCESS);
    }
    else
    {
        /* Fork and execute command */
        pid_t child_pid = fork();

        if (child_pid == 0)
	{
            /* Child process */
            if (execve(tokens[0], tokens, NULL) == -1)
	    {
                perror("execvp");
                exit(EXIT_FAILURE);
            }
        } else if (child_pid < 0) {
            perror("fork");
        }

        /* Parent process waits for the child */
        wait4child();
    }

    /* Free memory allocated for tokens */
    for (i = 0; tokens[i] != NULL; i++)
    {
        free(tokens[i]);
    }
    free(tokens);
}



