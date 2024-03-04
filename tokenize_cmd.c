#include "main.h"

/**
 * tokenize_cmd - splits input strings into tokens
 * Returns: an array of tokens
 */


tokenized_data tokenize_cmd(char *input_string, const char *delimiter) {
	int index, array_size, i;
	tokenized_data data;
	char *token;

	index = 0;
	array_size = 8;
	data.tokens_count = 0;

	data.tokens_array = malloc(sizeof(char *) * array_size);
	if (data.tokens_array == NULL) {
		perror("Memory allocation error");
		return (data);
	}

	token = strtok(input_string, delimiter);
	while (token != NULL) {
		data.tokens_array[index] = strdup(token);
		if (data.tokens_array[index] == NULL) {
			perror("Memory allocation error");
			for (i = 0; i < index; i++) {
				free(data.tokens_array[i]);
			}
			free(data.tokens_array);
			return (data);
		}

		index++;
		data.tokens_count++;
		if (index >= array_size) {
			array_size *= 2;
			data.tokens_array = reallocate_mem(data.tokens_array, (sizeof(char *) *(array_size - 1)),
							   (sizeof(char *) * array_size));
			if (data.tokens_array == NULL) {
				perror("Memory reallocation error");
				return (data);
			}
		}
		token = strtok(NULL, delimiter);
	}

	data.tokens_array[index] = NULL;
	return (data);
}
