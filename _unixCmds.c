#include "main.h"


/**
 * _ls - handles the ls command
 * @path: path to directory
 */

void _ls(const char *path)
{
    DIR *dir;
    struct dirent *entry;

    dir = opendir(path);
    if (dir == NULL)
    {
        perror("opendir");
        return;
    }

    while ((entry = readdir(dir)) != NULL) {
        printf("%s\n", entry->d_name);
    }
    closedir(dir);
}


/**
 * _pwd - prints current working directory,
 */

void _pwd()
{
    char cwd[1024];

    if (getcwd(cwd, sizeof(cwd)) != NULL)
    {
        write(STDOUT_FILENO, cwd, strlen(cwd));
        write(STDOUT_FILENO, "\n", 1);
    }
    else
    {
        perror("_pwd");
    }
}


/**
 * clearTerminal - clears the terminal
 */

void clearTerminal()
{
    /* On Windows */
    #ifdef _WIN32
        system("cls");

    /* On Unix Systems*/
    #else
        system("clear");

    #endif
}


/**
 * _cd - changes directory to specified path,
 * @path: Path to change directory to.
 */

void _cd(const char *path)
{
    if (chdir(path) != 0)
    {
        perror("cd");
    }
}


/**
 * exitTerminal - exits terminal
 */

void exitTerminal()
{
    const char *message;
    message = "Exiting the shell.....\n";

    write(STDOUT_FILENO, message, strlen(message));
    exit(EXIT_SUCCESS);
}