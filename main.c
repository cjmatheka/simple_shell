#include "main.h"

/**
 * main: starting point of our program
 * argc: number of arguments in a command line
 * argv: the array of pointers to the arguments in the command line
 * return: 0 if successful
 */
int main(int argc, char *argv[])
{
	void input_controller;
	int a = 1;
		char *line = NULL;
		char *input = argv[0];
		ssize_t geterror = 0;
		size_t result = 0;
		 

		while (a <= 1)
		{
		line = NULL 
		geterror = getline(&line, result, stdin);
		if (geterror <= 1)
			{
				free(line);
				exit(0);
			}
		input_controller(&line, input);
		free(line);
		}
		return (0);
}
