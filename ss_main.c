#include "main.h"

/**
* main - Entry point for the project
*/

#define MAX_COMMAND_LENGTH 1024


int main() {
	char *command = NULL;
	size_t bufsize = 0;
	char prompt[] = "#Maosh$ ";
	pid_t pid;
	int status;

	while (1) {
		/* Display prompt */
		if (isatty(STDIN_FILENO)) {
			write(STDOUT_FILENO, prompt, strlen(prompt));
			fflush(stdout);
		}

		/* Read command from user using getline */
		if (getline(&command, &bufsize, stdin) == -1) {
			/* Handle EOF (Ctrl+D) */
			break;
		}

		/* Remove the newline character from the command */
		command[strcspn(command, "\n")] = 0;

		/* Fork a child process */
		pid = fork();

		if (pid == -1) {
			/* Error occurred */
			perror("fork");
		} else if (pid == 0) {
			/* Child process */
			/* Execute the command */
			if (execlp(command, command, (char *) NULL) == -1) {
				/* If execution fails, print error and exit */
				perror("exec");
				exit(EXIT_FAILURE);
			}
		} else {
			/* Parent process */
			/* Wait for child to terminate */

			if (dup2(STDIN_FILENO, 0) == -1) {
				perror("dup2");
				exit(EXIT_FAILURE);
			}

			waitpid(pid, &status, 0);

		}
	}

	/* Free dynamically allocated memory */
	free(command);

	return 0;
}