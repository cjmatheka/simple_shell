cmake_minimum_required(VERSION 3.26)
project(Simple_Shell C)

set(CMAKE_C_STANDARD 11)

include_directories(.)

add_executable(Simple_Shell
        _fpath.c
        _getenv.c
        _printstr.c
        _putchar.c
        _strcmp.c
        _strcpy.c
        _strcspn.c
        _strdup.c
        _strlen.c
        _strncmp.c
        _strtok.c
        clearTerminal.c
        executeCommands.c
        exit.c
        exitTerminal.c
        freeCmds.c
        main.h
        maoshInit.c
        processInput.c
        shellEnv.c
        ss_main.c
        waitHelper.c
        handleCommand.c)
