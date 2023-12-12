#include "main.h"

/**
* process_commands - processes user input,
 * @line: line to process,
 * Return: Token,
*/

char** processInput(char *line) {
    /*Remove the newline character at the end */
    line[strcspn(line, "\n")] = '\0';

    /* Tokenize the input line to extract words */
    char *token = strtok(line, " ");

    if (token == NULL) {
        /* No command entered, return NULL */
        return NULL;
    }

    /* Allocate an array to store tokens */
    char **tokens = malloc(sizeof(char*));
    if (tokens == NULL) {
        perror("malloc");
        exit(EXIT_FAILURE);
    }

    /* Copy the first token (command) to the array */
    tokens[0] = strdup(token);

    /* Continue tokenizing and copying the rest of the tokens */
    int count = 1;
    while ((token = strtok(NULL, " ")) != NULL) {
        tokens = realloc(tokens, (count + 1) * sizeof(char*));
        if (tokens == NULL) {
            perror("realloc");
            exit(EXIT_FAILURE);
        }

        tokens[count] = strdup(token);
        count++;
    }

    /* Add a NULL pointer at the end to indicate the end of the array */
    tokens = realloc(tokens, (count + 1) * sizeof(char*));
    if (tokens == NULL) {
        perror("realloc");
        exit(EXIT_FAILURE);
    }
    tokens[count] = NULL;

    /* Return the array of tokens */
    return tokens;
}