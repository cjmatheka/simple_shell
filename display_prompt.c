#include "main.h"

/**
 * display_prompt - displays prompt
 */

void display_prompt() {
	char prompt[] = "#Maosh$ ";
	if (isatty(STDIN_FILENO)) {
		write(STDOUT_FILENO, prompt, strlen(prompt));
		fflush(stdout);
	}
}