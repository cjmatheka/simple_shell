#include "main.h"

/**
 * read_cmd - displays prompt
 */

char *read_cmd() {
	size_t bufsize = 0;
	char *cmd = NULL;


	if (getline(&cmd, &bufsize, stdin) == -1) {
		return (NULL);
	}
	/*Remove newline*/
	cmd[strcspn(cmd, "\n")] = 0;
	return (cmd);
}