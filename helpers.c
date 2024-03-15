#include "main.h"

/**
 * _handle_trailing_slash - handles trailing slash
 * @param str
 * @return
 */

char *_handle_trailing_slash(char *string) {
	int len;
	char *result;

	len = strlen(string);

	result = _strdup(string);

	if (result[len - 1] != '/') {
		result = str_concat(2, result, "/");
	}

	return (result);
}