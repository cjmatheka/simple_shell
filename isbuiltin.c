#include "main.h"

/**
 * isbuiltins - checks of a command is builtin
 * @args: arguments array
 */
void (*isbuiltin(char **args))(char **args) {
	int i, j;

	my_builtins T[] = {
		{"exit",     _exiting},
		{"env",      _env},
		{"setenv",   _setenv},
		{"unsetenv", _unsetenv},
		{NULL,       NULL}
	};

	for (i = 0; T[i].name; i++) {
		j = 0;
		if (T[i].name[j] == args[0][j]) {
			for (j = 0; args[0][j]; j++) {
				if (T[i].name[j] != args[0][j])
					break;
			}
			if (!args[0][j])
				return (T[i].func);
		}
	}
	return (0);
}