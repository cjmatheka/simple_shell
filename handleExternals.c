#include "main.h"
/**
* handleExternals - Executes commands,
 * @tokens: Commands to execute,
*/

void handleExternals(char **tokens)
{
    pid_t child_pid;
    char *path, *path_copy, *dir, *full_path;

    child_pid = fork();
    if (child_pid == 0) /* Child process */
    {
        path = getenv("PATH");
        path_copy = strdup(path);
        dir = strtok(path_copy, ":");

        while (dir != NULL)
        {
            full_path = malloc(strlen(dir) + strlen(tokens[0]) + 2);
            if (full_path == NULL)
            {
                exit(EXIT_FAILURE);
            }
            strcpy(full_path, dir);
            strcat(full_path, "/");
            strcat(full_path, tokens[0]);

            if (cmdExists(full_path))
            {
                execve(full_path, tokens, environ);
            }
            free(full_path);
            dir = strtok(NULL, ":");
        }
        fprintf(stderr, "Command not found: %s\n", tokens[0]);
        free(path_copy);
        exit(EXIT_FAILURE);
    }
    else if (child_pid < 0)
    {
        perror("Process not created");
    }
    else
    {
        wait4child();
    }
}



