#include "main.h"

/**
 * executeCommands - execute commands
 * @line: commands
 */

void executeCommands(char **tokens)
{
	pid_t pid;
	char **env_ptr = environ;


	/* Check for the "exit" command */
	if (_strcmp(tokens[0], "exit") == 0)
	{
		write(STDOUT_FILENO, "\nExiting Shell\n", 15);
		exit(EXIT_SUCCESS);
	}
	else if (_strcmp(tokens[0], "env") == 0)
	 {
		while (*env_ptr != NULL)
		{
			printf("%s\n", *env_ptr);
			env_ptr++;
		}
		return;
	 }

	 /* Fork a new process */
	 pid = fork();

	 if (pid == -1)
	 {
		 /* Error handling for fork failure */
		 perror("fork");
		 exit(EXIT_FAILURE);
	 }
	 else if (pid == 0)
	 {
		 /* Child process. Execute the command using execvp */
		 if (execve(tokens[0], tokens, environ) == -1)
		 {
			 /* Handle command not found */
			 perror("exec");
			 exit(EXIT_FAILURE);
		 }
	 }
	 else
	 {
		 /* Parent process. Wait for the child process to complete */
		 wait4child();
	 }
}
