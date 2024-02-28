#include "main.h"

/**
* main - Entry point for the project
*/

int main(void) {
	int status, display_prompt;
	char *line = NULL, *args[2];
	size_t len;
	ssize_t input;
	pid_t pid;

	status = 1;
	while (status) {
		display_prompt = 1;

		if (isatty(STDIN_FILENO)) {
			write(STDOUT_FILENO, "hsh$ ", 6);
			fflush(stdout);
		} else {
			display_prompt = 0;
		}

		/* Read input from user */
		len = 0;
		input = getline(&line, &len, stdin);
		if (input == -1) {
			break;
		}

		len = strlen(line);
		if (line[len - 1] == '\n') {
			line[len - 1] = '\0';
		}

		/* Skip empty lines */
		if (strlen(line) == 0) {
			continue;
		}


		/* Fork a child process */
		pid = fork();

		if (pid == 0) {
			/* Child process */
			args[0] = line;
			args[1] = NULL;


			if (execve(args[0], args, NULL) == -1) {
				perror("./hsh");
			}
			exit(0);
		} else if (pid < 0) {
			perror("./hsh");
		} else {
			wait(NULL);
			if (display_prompt) {
				dup2(STDIN_FILENO, 0);
			}
		}
	}
	free(line);

	return (0);

}