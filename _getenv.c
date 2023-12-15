#include "main.h"

/**
* _getenv - gets the user name from environment,
 * @name: name provided by the user,
 * Return: User name on success, Null on failure.
*/

char *_getenv(const char *name)
{
	/* declare local variables */
	char **env;

	if (name == NULL || environ == NULL)
	{
		/* Invalid input*/
		return (NULL);
	}

	/* Iterate through the environment variables */
	for (env = environ; *env != NULL; env++)
	{
		if (_strncmp(*env, name, _strlen(name)) == 0 && (*env)[_strlen(name)] == '=')
		{
			/* Found the environment variable */
			return (*env + _strlen(name) + 1);
		}
	}
	/* Environmental variable not found */
	return (NULL);
}
