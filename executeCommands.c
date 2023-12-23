#include "main.h"

/**
 * executeCommands - exeute commands
 * @line: commands
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

    tokens = malloc(sizeof(char *) * MAX_TOKENS);
    if (tokens == NULL)
    {
        perror("Unable to allocate memory");
        exit(EXIT_FAILURE);
    }

    /* Copy tokens to array */
    do {
        tokens[count] = _strdup(token);
        count++;

        token = _strtok(NULL, " ");
    } while (token != NULL && count < MAX_TOKENS - 1);

    /* Add a NULL pointer at the end to indicate the end of the array */
    tokens[count] = NULL;

    /* Check if it's a built-in command and use system */
    if (_strcmp(tokens[0], "cd") == 0 || _strcmp(tokens[0], "pwd") == 0 || _strcmp(tokens[0], "clear") == 0
        || _strcmp(tokens[0], "env") == 0)
    {
        handleBuiltins(line);
    }
    else if (_strcmp(tokens[0], "exit") == 0)
    {
        exit(EXIT_SUCCESS);
    }
    else
    {
        /* Check if the command exists in the PATH */
        if (cmdExists(tokens[0]))
	{
            handleExternals(tokens);
        }
	else
	{
            printf("Command not found in PATH: %s\n", tokens[0]);
        }
    }

    /* Free memory allocated for tokens */
    for (i = 0; i < count; i++) {
        free(tokens[i]);
    }
    free(tokens);
}