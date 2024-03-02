#include "main.h"

/**
 * parse_cmd - parses command
 */

void parse_cmd(char *cmd, char **args) {
	char *token;
	int i;

	token = strtok(cmd, " ");
	i = 0;

	while (token != NULL && i < MAX_COMMAND_LENGTH) {
		args[i] = token;
		i++;
		token = strtok(NULL, " ");
	}
	args[i] = NULL;
}