#include "main.h"

/**
* main - Entry point for the project
*/


int main(int argc, char *argv[]) {
	char *command = NULL;
	(void)argc;
	(void)argv;

	while (1) {
		display_prompt();
		command = read_cmd();

		if (command == NULL) {
			break;
		}

		execute_cmd(command);

		free(command);
		command = NULL;
	}
	return (0);
}