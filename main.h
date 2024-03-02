#ifndef MAIN_H
#define MAIN_H

#define MAX_COMMAND_LENGTH 1024

/* Standard libraries */
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>


/* Functions prototypes*/
int main(int argc, char *argv[]);
void display_prompt();
char *read_cmd();
void parse_cmd(char *cmd, char **args);
void execute_cmd(char **args);

#endif