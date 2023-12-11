#include "main.h"

/**
 * exit -0 if sucessfull
 *
 */
void _shellexit(int exit_status)
{
	if(exit_stutus == 1)
	{
		printf("exiting is unsuccessful!!... \n");
		//unsuccessful simulation for exit
		exit (1);
	}
	else
	{
		printf("You're now exiting charles' and ruth's shell!...\n");
		//successful simulatin for exit
		exit (0);
	}
}
