#ifndef MAIN_H
#define MAIN_H

/* Defining the clear function */
#define _clear() write(STDOUT_FILENO, "\033[H\033[J", 7)
#define MAX_COMMAND_LENGTH 100
#define MAX_ARGS 100
#define MAX_LENGTH 1000
#define MAX_COMMAND_LENGTH 100
#define MAX_PATH_LENGTH 1000
#define MAX_TOKENS 100


/* The library/header files are included here */
#include<errno.h>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<unistd.h>
#include<stddef.h>
#include <stdarg.h>
#include<time.h>
#include <dirent.h>
#include <sys/stat.h>
#include<sys/types.h>
#include <inttypes.h>
#include<sys/wait.h>
#include <fcntl.h>
#include <sys/types.h>
#include <ftw.h>

/* Declaring global variables */
extern char **environ;
typedef int64_t custom_time_t;

/* The function prototypes are included here */
void shell_init(void);
int dollar_sign(void);
size_t _strlen(const char *str);
int _strncmp(const char *s1, const char *s2, size_t n);
int _putchar(char c);
char *_getenv(const char *name);
time_t _time(time_t *tloc);
void _exitShell(int exit_status);
size_t _strcspn(const char *str, const char *reject);
void _strcpy(char *dest, const char *src);
char *_strdup(const char *str1);
int _strcmp(const char *s1, const char *s2);
void _ls(const char *path, const char *options);
void _pwd(void);
void _cd(const char *path);
char *_strtok(char *str, const char *delimiters);
void executeCommands(char **tokens);
void wait4child(void);
char **tokenizeInput(char *line);

#endif
