#ifndef MAIN_H
#define MAIN_H

extern char **environ;

                                    /* STANDARD LIBRARIES */
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdarg.h>
#include <sys/stat.h>

                                   /* DATA STRUCTURES */
/**
 * struct my_builtins - pointer to function with corresponding builtin command
 * @name: name of builtin
 * @func: function fr executing the builtin
 */
typedef struct my_builtins
{
    char *name;
    void (*func)(char **);
} my_builtins;

typedef enum { false, true } bool;

/**
 * struct list_path - data structure linked list
 * @dir: directory
 * @p: pointer to the next node
 */
typedef struct list_path {
    char *dir;
    struct list_path *p;
} list_path;

/**
 * tokenized_data - data structure for holding tokens array and tokens count
 * token_array - array of tokens
 * count - tokens count
 */
typedef struct tokenized_data {
  char **tokens_array;
  int tokens_count;
} tokenized_data;

                                     /* FUNCTION PROTOTYPES */
int main(void);
void _isatty(void);
void handle_signal(int signal_number);
void display_prompt(void);
void handle_eof(int length, char *buffer);
void execute_cmd(tokenized_data data, list_path *head);
tokenized_data tokenize_cmd(char *input_string, const char *delimiter);
void *reallocate_mem(void *ptr, unsigned int old_size, unsigned int new_size);
void free_tokenized_data(tokenized_data data);
char *_strdup(char *string);
char *str_concat(int count, ...);
int _strlen(char *string);
int _putchar(char character);
void _puts(char *string);
int _strncmp(const char *s1, const char *s2, size_t n);
void _exiting(char **args);
int my_atoi(char *c);
void _env(char **args __attribute__ ((unused)));
void _setenv(char **args);
void _unsetenv(char **args);
void (*isbuiltin(char **args))(char **args);
char *_getenv(const char *var_name);
void free_list(list_path *head);
char *_which(char *filename, list_path *head);
list_path *adding_node(list_path **head, char *str);
list_path *process_path(char *path);
char *_getenv(const char *var_name);
char *_handle_trailing_slash(char *string);


#endif