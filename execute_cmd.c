#include "main.h"

/**
 * execute_cmd - Execute the command
 */

void execute_cmd(char *command) {
	char *args[MAX_COMMAND_LENGTH];
	char *token;
	pid_t pid;
	int i, status;

	token = strtok(command, " ");
	i = 0;

	while (token != NULL && i < MAX_COMMAND_LENGTH) {
		args[i] = token;
		i++;
		token = strtok(NULL, " ");
	}
	args[i] = NULL;

	pid = fork();

	if (pid < 0) {
		perror("fork");
	} else if (pid == 0) {
		/* Child Process: Attempt execution */
		if (execve(args[0], args, NULL) == -1) {
			perror("execve");
		}
		exit(EXIT_FAILURE);
	} else {
		/* Parent Process: Wait for child */
		waitpid(pid, &status, 0);
	}
}
