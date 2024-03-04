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
	while (token) {
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

	new_node->dir = str;
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
	/* Declare variables */
	struct stat st;
	char *string;
	list_path *tmp;

	/* Initialize variables */
	tmp = head;

	/* Concatenates directory, "/", and filename */
	while (tmp) {
		string = str_concat(3, tmp->dir, "/", filename);
		if (stat(string, &st) == 0) {
			return (string);
		}
		free(string);
		tmp = tmp->p;
	}

	/* Return NULL if the file is not found in any directory */
	return (NULL);
}