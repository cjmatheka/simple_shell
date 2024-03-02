#include "main.h"

/**
* main - Entry point for the project
*/


int main(int argc, char *argv[]) {
	char *command = NULL;
	char *args[MAX_COMMAND_LENGTH];
	(void)argc;
	(void)argv;

	while (1) {
		display_prompt();
		command = read_cmd();

		if (command == NULL) {
			break;
		}

		parse_cmd(command, args);
		execute_cmd(args);

		free(command);
		command = NULL;
	}
	return (0);
}