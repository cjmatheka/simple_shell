#include "main.h"

/**
 * execute_cmd - Execute the command
 */

void execute_cmd(tokenized_data data, list_path *head) {
    pid_t pid;
    int status;
    char *path;

    pid = fork();

    if (pid < 0) {
        perror("fork");
    } else if (pid == 0) {
        /* Child Process: Attempt execution */
        path = _which(data.tokens_array[0], head);

         if (path) {
             data.tokens_array[0] = path;
             if (execve(data.tokens_array[0], data.tokens_array, NULL) == -1) {
                 perror("execve");
             }
             free(path);
             exit(EXIT_FAILURE);
         } else {
             perror("Command not found");
             exit(EXIT_FAILURE);
         }
    } else {
        /* Parent Process: Wait for child */
        waitpid(pid, &status, 0);
    }
}
