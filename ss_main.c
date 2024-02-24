#include "main.h"

/**
* main - Entry point for the project
*/

int main(void)
{
	int status;
	char *line = NULL;
	char *args[2];
	size_t len;
        ssize_t input, max_size;
	pid_t pid;

	status = 1;
	while (status)
	{
		printf("$ ");
		fflush(stdout);

		/* Read input from user */
		max_size =100;
		input = getline(&line, &len, stdin);
		if (input == -1)
		{
			break;
		}
		else if (input >= max_size)
		{
			perror("Input too long");
		}

		len = strlen(line);
		if (line[len - 1] == '\n')
		{
			line[len - 1] = '\0';
		}

		/* Skip empty lines */
		if (strlen(line) == 0)
		{
			continue;
		}



		/* Tokenize to just get the command name */
		args[0] = strtok(line, " ");
		args[1] = NULL;

		/* Fork a child process */
		pid = fork();

		if (pid == 0)
		{
			/* Child process */
			if (execve(args[0], args, NULL) == -1)
			{
				perror("./hsh");
			}
			_exit(0);
		}
		else if (pid < 0)
		{
			perror("./hsh");
		}
		else
		{
			wait(NULL);
		}
	}
	free(line);

	return (0);
}