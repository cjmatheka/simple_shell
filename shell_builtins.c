#include "main.h"

/**
 * _exit - exits the terminal
 * @args: arrays of arguments to clear before exiting
 */
void _exiting(char **args) {
	/* Declare variables */
	int i, status;

	/* Initialize n with 0 */
	status = 0;

	/* Check if there is at least one argument */
	if (args[1]) {
		status = atoi(args[1]);
		if (status <= -1)
			status = 2;
		for (i = 0; args[i]; i++)
			free(args[i]);
	}
	free(args);
	exit(status);
}

/**
 * my_atoi - converts character c to integer datatype
 * @c: character to convert
 * Return: converted integer
 */
int my_atoi(char *c) {
	/* Variable declarations */
	int i, my_int, sign;

	/* variable initialization */
	i = 0;
	my_int = 0;
	sign = 1;

	/* Skip leading non-digit characters */
	while (c[i] != '\0' && !(c[i] >= '0' && c[i] <= '9')) {
		if (c[i] == '-') {
			sign *= -1;
		}
		i++;
	}

	/* Convert digits to integer */
	while (c[i] >= '0' && c[i] <= '9') {
		my_int = my_int * 10 + (c[i] - '0');
		i++;
	}

	return (my_int * sign);
}

/**
 * _env - prints current environment
 * @args: arguments array
 */
void _env(char **args __attribute__ ((unused))) {
	int i;

	/* Print the environment variable followed by a newline */
	for (i = 0; environ[i]; i++) {
		_puts(environ[i]);
	}
}


/**
 * _setenv - sets or updates environmental variables
 * @args: argument arrays
 */
void _setenv(char **args) {
	int i, j, k, length;

	if (!args[1] || !args[2]) {
		perror(_getenv("_"));
		return;
	}

	for (i = 0; environ[i]; i++) {
		j = 0;
		if (strncmp(args[1], environ[i], strlen(args[1])) == 0) {
			k = 0;
			while (args[2][k]) {
				environ[i][j + 1 + k] = args[2][k];
				k++;
			}
			environ[i][j + 1 + k] = '\0';
			return;
		}
	}

	if (!environ[i]) {
		printf("Adding new environment variable: %s=%s\n", args[1], args[2]);

		length = strlen(args[1]) + strlen(args[2]) + 2;
		environ[i] = (char *) malloc(length * sizeof(char));
		snprintf(environ[i], length, "%s=%s", args[1], args[2]);
		environ[i + 1] = NULL;
	}
}


/**
 * _unsetenv - removes environmental variable if it exists
 * @args: arguments array
 */
void _unsetenv(char **args) {
	int i;

	if (!args[1]) {
		puts("Error: No argument provided.");
		return;
	}

	for (i = 0; environ[i]; i++) {
		if (_strncmp(args[1], environ[i], strlen(args[1])) == 0) {
			free(environ[i]);
			while (environ[i + 1]) {
				environ[i] = environ[i + 1];
				i++;
			}
			environ[i] = NULL;
			return;
		}
	}
}