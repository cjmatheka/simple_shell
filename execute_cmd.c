#include "main.h"

/**
 * execute_cmd - Execute the command
 */

void execute_cmd(tokenized_data data) {
	pid_t pid;
	int status;

	pid = fork();

	if (pid < 0) {
		perror("fork");
	} else if (pid == 0) {
		/* Child Process: Attempt execution */
		if (execve(data.tokens_array[0], data.tokens_array, NULL) == -1) {
			perror("execve");
		}
		exit(EXIT_FAILURE);
	} else {
		/* Parent Process: Wait for child */
		waitpid(pid, &status, 0);
	}
}
