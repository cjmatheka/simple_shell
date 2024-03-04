#include "main.h"

/**
 * reallocate_mem - reallocates memory
 * @param ptr
 * @param old_size
 * @param new_size
 * @return
 */
void *reallocate_mem(void *ptr, unsigned int old_size, unsigned int new_size) {
	char *new_ptr;

	if (ptr == NULL)
		return malloc(new_size);

	if (new_size == 0) {
		free(ptr);
		return (NULL);
	}

	new_ptr = malloc(new_size);
	if (new_ptr == NULL)
		return (NULL);

	memcpy(new_ptr, ptr, new_size < old_size ? new_size : old_size);

	free(ptr);
	return (new_ptr);
}


/**
 * free_tokens_array - frees array
 * @arr: arr to free
 */
void free_tokenized_data(tokenized_data data) {
	int i;

	if (data.tokens_array != NULL) {
		for (i = 0; i < data.tokens_count; i++) {
			free(data.tokens_array[i]);
		}
		free(data.tokens_array);
	}
}


/**
 * free_list - free linked list
 * @head: head to the list
 */
void free_list(list_path *head) {
	/* Declare variables */
	list_path *current_node;
	list_path *next_node;

	/*Initialize current node */
	current_node = head;

	/* Free list */
	while (current_node != NULL) {
		next_node = current_node->p;
		free(current_node->dir);
		free(current_node);
		current_node = next_node;
	}
}