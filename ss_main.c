#include "main.h"

/**
* main - Entry point for the project
*/

#define MAX_COMMAND_LENGTH 1024


int main(int argc, char *argv[]) {
	char *args[MAX_COMMAND_LENGTH];
	char *command = NULL;
	char *tokens;
	size_t bufsize = 0;
	char prompt[] = "#Maosh$ ";
	pid_t pid;
	int status, i;
	(void)argc;

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

		/* Tokenize the command */
		tokens = strtok(command, ";");

		while (tokens != NULL) {
			pid = fork();
			if (pid == -1) {
				perror("fork");
			} else if (pid == 0) {
				/* Child process */
				args[0] = tokens;

				i = 1;
				while (argv[i] != NULL) {
					args[i] = argv[i];
					i++;
				}
				args[i] = NULL;

				if (execve(tokens, args, NULL) == -1) {
					perror("execve");
					exit(EXIT_FAILURE);
				}
			} else {
				/* Parent Process: waitpid ... */
				waitpid(pid, &status, 0);
			}

			tokens = strtok(NULL, " ");
		}
	}

	/* Free dynamically allocated memory */
	free(command);

	return 0;
}