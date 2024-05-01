#include "main.h"

/**
 * _getenv - searches for env variable by name
 * @var_name - env variable name to search for.
 * Return: return env var value
 */
char *_getenv(const char *var_name) {
	/* Declare variables */
	int i, j;

	/*Check if name is NULL */
	if (!var_name)
		return (NULL);

	/* Loop through the environment variables */
	for (i = 0; environ[i]; i++) {
		j = 0;
		while (var_name[j] && var_name[j] == environ[i][j])
			j++;
		if (var_name[j] == '\0')
			return (environ[i] + j + 1);
	}

	/* Return NULL if no match is found */
	return (NULL);
}

/**
 * process_path - processes path
 * @path - path to process
 * return: head
 */
list_path *process_path(char *path) {
	/* Declare variables */
	list_path *head;
	char *token;
	char *cpath;

	/* Initialize the head pointer to NULL */
	head = NULL;
	cpath = _strdup(path);

	if (!cpath)
		return (NULL);

	token = strtok(cpath, ":");
	printf("DEBUG: First token: %s\n", token);
	while (token) {
		printf("DEBUG: Extracted directory: %s\n", token);
		head = adding_node(&head, token);
		token = strtok(NULL, ":");
	}

	free(cpath);

	return (head);
}

/**
 * adding_node - adds a node to a linked list
 * @head: head to the list
 * @str: data for the new node
 * Return: head to the list
 */
list_path *adding_node(list_path **head, char *str) {
	list_path *new_node;
	/* Check if str is NULL */
	if (!str)
		return (NULL);

	/* Allocate memory for the new node */
	new_node = malloc(sizeof(list_path));

	if (!new_node)
		return (NULL);

	new_node->dir = _strdup(str);
	new_node->p = NULL;

	/* If head is NULL, make the new node the head */
	if (!*head) {
		*head = new_node;
	} else {
		list_path *tmp = *head;
		while (tmp->p) {
			tmp = tmp->p;
		}
		tmp->p = new_node;
	}

	/* Return a pointer to the head of the list */
	return (*head);
}

/**
 * _which - finds a file in a linked list
 * @filename: name of file
 * @head: head to the list
 * Return: first path where file is found
 */
char *_which(char *filename, list_path *head) {
	struct stat st;
	char *string = NULL;
	list_path *tmp = head;
	char *full_path = NULL;

	if (filename == NULL || head == NULL) {
		printf("ERROR: Invalid arguments.\n");
		return (NULL);
	}

	if (strchr(filename, '/') != NULL) {
		string = str_concat(1, filename);
		if (string == NULL) {
			printf("ERROR: Memory allocation failed.\n");
			return (NULL);
		}
		if (stat(full_path, &st) == 0 && st.st_mode & S_IXUSR) {
			return (string);
		}
		free(string);
	}
	prints("Debug: Full Path To Check: %s", full_path)

	while (tmp != NULL) {
		string = _handle_trailing_slash(tmp->dir);

		if (string == NULL) {
			printf("ERROR: Memory allocation failed.\n");
			return (NULL);
		}
		full_path = str_concat(2, string, filename);
		free(string);
		if (full_path == NULL) {
			printf("ERROR: Memory allocation failed.\n");
			return (NULL);
		}
        
		if (stat(full_path, &st) == 0) {
			printf("DEBUG: File found in Full Path: %s\n", full_path);
            return(full_path);
		} else {
			printf("DEBUG: File not found.\n");
			return (NULL);
		}
		free(full_path);
		tmp = tmp->p;
	}

	return (NULL);
}