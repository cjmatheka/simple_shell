#include "main.h"

/*
 * _printenv - prints the current environment variables
 *
 */

void _printenv(void)
{
	char *env = environ;
		while(*env != NULL){
		size_t len = 0;
		while((*env) [len] != '\0'){
			len++;
		}
		write(STDOUT_FILENO, *env, len);
		write(STDOUT_FILENO, "\n", 1);
		env++;
		}
}
