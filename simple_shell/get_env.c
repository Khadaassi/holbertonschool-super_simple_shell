#include "main.h"
/**
 * _getenv - Retrieves the value of an environment variable.
 * @name: The name of the environment variable to retrieve.
 * Description:
 * This function searches for the specified environment variable by name
 * and returns its value. If the variable is not found, it returns NULL.
 * Parameters:
 * @name: Name of the environment variable to retrieve.
 * Return:
 * Returns the value of the environment variable or NULL if not found.
 */
char *_getenv(const char *name)
{
	int i = 0;
	char *key;

	while (environ[i])
	{
		key = strtok(environ[i], "=");

		/* Check if the current environment variable matches the given name */
		if (strcmp(key, name) == 0)
			return (strtok(NULL, "="));

		i++;
	}

	/* Return NULL if the environment variable is not found */
	return (NULL);
}
