#include "main.h"

/**
 * handle_signal - Execute the command
 */
void handle_signal(int signal_number) {
    if (signal_number == SIGINT) {
        printf("\n#Maosh$ ");
        fflush(stdout);
    }
}

/**
 * execute_cmd - Execute the command
 */
void handle_eof(int length, char *buffer) {
    if (length == -1) {
        if (isatty(STDIN_FILENO)) {
            printf("\n");
            free(buffer);
        }
        exit(0);
    }
}

/**
 * execute_cmd - Execute the command
 */
void display_prompt(void) {
    if (isatty(STDIN_FILENO)) {
        printf("#Maosh$ ");
        fflush(stdout);
    }
}