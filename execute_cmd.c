#include "main.h"

/**
 * execute_cmd - Execute the command
 */

void execute_cmd(char **args) {
	pid_t pid;
	int status;

	pid = fork();

	if (pid == -1) {
		perror("fork");
	} else if (pid == 0) {
		if (execve(args[0], args, NULL) == -1) {
			perror("execve");
			exit(EXIT_FAILURE);
		}
	} else {
		waitpid(pid, &status, 0);
	}
}