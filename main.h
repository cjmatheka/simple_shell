#ifndef MAIN_H
#define MAIN_H

/* Defining the clear function */
#define _clear() write(STDOUT_FILENO, "\033[H\033[J", 7)
#define MAX_COMMAND_LENGTH 100


/* The library/header files are included here */
#include <stdin.h>
#include <errno.h>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<unistd.h>
#include <stddef.h>
#include <time.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<readline/readline.h>
#include<readline/history.h>

/* Declaring global variables */
extern char **environ;
typedef int64_t custom_time_t;

/* The function prototypes are included here */
int main(int argc, char *argv[]);
void shell_init();
int dollar_sign();
size_t _strlen(const char *str);
int _strncmp(const char *s1, const char *s2, size_t n);
int _putchar(char c);
char *_getenv(const char *name);
void _printstr(const char *str);
time_t _time(time_t *tloc);
void _shellexit(int exit_status);

#endif
