#include "main.h"

/**
* main - Entry point for the project
*/


int main(void) {
	ssize_t length;
	size_t size;
	char *buffer = NULL, *value, *path;
	list_path *head;
	tokenized_data data;
	void (*function)(char **);

	size = 0;
	head = NULL;

	signal(SIGINT, handle_signal);
	while (1) {

		display_prompt();

		length = getline(&buffer, &size, stdin);
		if (length == -1) {
			break;
		}

		handle_eof(length, buffer);
		printf("DEBUG: Raw User Input: %s\n", buffer);

		data = tokenize_cmd(buffer, " ");
		printf("DEBUG: First Token: %s\n", data.tokens_array[0]);

		if (!data.tokens_array || !data.tokens_array[0]) {
			execute_cmd(data, head);
		} else {
			value = _getenv("PATH");
			printf("DEBUG: Raw PATH: %s\n", value);
			head = process_path(value);
			path = _which(data.tokens_array[0], head);
			printf("DEBUG: Path returned by _which: %s\n", path);
			function = isbuiltin(data.tokens_array);
			if (function) {
				free_tokenized_data(data);
				function(data.tokens_array);
			} else if (!path) {
				execute_cmd(data, head);
			} else {
				free_tokenized_data(data);
				data.tokens_array[0] = path;
				execute_cmd(data, head);
			}
		}
		free_tokenized_data(data);
	}
	free(buffer);
	return (0);
}