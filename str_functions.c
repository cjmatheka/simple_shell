#include "main.h"


/**
 * _strdup - Duplicates a string
 * @string: string to duplicate
 * Return: duplicated string.
 */
char *_strdup(char *string) {
	int i, length;
	char *string_dup;

	if (!string)
		return (NULL);

	length = _strlen(string);
	string_dup = malloc(length + 1);
	if (!string_dup)
		return (NULL);

	for (i = 0; i < length; i++)
		string_dup[i] = string[i];

	return (string_dup);
}

/**
 * _strncmp - compares strings
 * @s1: first string to compare
 * @s2: second string to compare
 * @n: num of characters to compare
 * Return: Integer less than, greater than, or 0.
 */
int _strncmp(const char *s1, const char *s2, size_t n) {
	while (n--) {
		if (*s1 != *s2)
			return (*s1 - *s2);
		else if (*s1 == '\0')
			return (0);
		s1++;
		s2++;
	}
	return (0);
}


/**
 * str_concat - concatenates all strings
 * @count: num of strings
 * @...: list of arbitrary strings
 * @Return: Concatenated string
 */
char *str_concat(int count, ...) {
	int total_length, i;
	char *result;
	va_list args;
	va_start(args, count);

	if (count <= 0)
		return (NULL);

	total_length = 0;
	for (i = 0; i < count; i++) {
		char *arg = va_arg(args, char *);
		if (arg == NULL) {
			va_end(args);
			return (NULL);
		}
		total_length += strlen(arg);
	}

	va_end(args);

	result = (char *) malloc(total_length + 1);
	if (result == NULL)
		return (NULL);

	result[0] = '\0';

	va_start(args, count);
	for (i = 0; i < count; i++) {
		char *arg = va_arg(args, char *);
		strcat(result, arg);
	}
	va_end(args);

	return (result);
}


/**
 * _strlen - calculates the length of a string
 * @string: string to calculate its length
 * Return: length of string
 */
int _strlen(char *string) {
	int slen;

	slen = 0;
	while (string[slen] != '\0')
		slen++;
	return (slen);
}


/**
 * _putchar - puts character to stdout
 * @character: character to print
 * Return: 1 on success
 */
int _putchar(char character) {
	return write(1, &character, 1);
}


/**
 * _puts -
 * @str:
 */
void _puts(char *string) {
	int i;

	for (i = 0; string[i] != '\0'; i++)
		_putchar(string[i]);
}