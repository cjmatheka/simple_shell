#include "main.h"

/**
 * _cat - connects and displays,
 * @filename: file itself,
 */

void _cat(const char *input)
{
	int fd;
	char buffer[4096];
	ssize_t bytesRead;

	pid_t child_pid = fork();

	if (child_pid == -1)
	{
		perror("fork");
		exit(EXIT_FAILURE);
	}

	if (child_pid == 0)
	{
		/* Child process */
		/* Check if input is a path or just a filename */
		if (access(input, F_OK) != -1)
		{
			/* Input is a path */
			fd = open(input, O_RDONLY);
		}
		else
		{
			/* Input is just a filename, assume it's in the current directory */
			char path[4096];
			snprintf(path, sizeof(path), "./%s", input);
			fd = open(path, O_RDONLY);
		}

		if (fd == -1)
		{
			perror("open");
			exit(EXIT_FAILURE);
		}

		while ((bytesRead = read(fd, buffer, sizeof(buffer))) > 0)
		{
			if (write(STDOUT_FILENO, buffer, bytesRead) != bytesRead) {
				perror("write");
				exit(EXIT_FAILURE);
			}
		}

		if (bytesRead == -1)
		{
			perror("read");
			exit(EXIT_FAILURE);
		}

		close(fd);
		exit(EXIT_SUCCESS);
	}
	else
	{
		/* Parent process waits for child */
		if (waitpid(child_pid, NULL, 0) == -1)
		{
			perror("waitpid");
			exit(EXIT_FAILURE);
		}
	}
}