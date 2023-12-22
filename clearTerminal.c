#include "main.h"

/**
 * clearTerminal - clears terminal screen
 */

void clearTerminal(void)
{
	/* On Windows */
	#ifdef _WIN32
		system("cls");

	/* On Unix Systems*/
	#else
		system("clear");
	#endif
}
