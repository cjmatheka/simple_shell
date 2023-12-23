#include "main.h"

/**
* handleBuiltins - handles builtin functions
 * @tokens: command and its parameters,
*/

void handleBuiltins(char **tokens)
{
	char **env;
	char cwd[1024];

	/* Check the command and perform the corresponding action */
	if (_strcmp(tokens[0], "cd") == 0)
	{
		if (tokens[1] != NULL)
			chdir(tokens[1]);
		chdir(".");
	}
	else if (_strcmp(tokens[0], "pwd") == 0)
	{
		if (getcwd(cwd, sizeof(cwd)) != NULL)
			printf("%s\n", cwd);
		perror("Could not print working directory");

	}
	else if (_strcmp(tokens[0], "clear") == 0)
		system("clear");
	else if (_strcmp(tokens[0], "env") == 0)
	{
		env = environ;
		while (*env != NULL)
		{
			printf("%s\n", *env);
			env++;
		}
	}
	else
	{
		printf("Unknown command %s\n", tokens[0]);
	}
}
