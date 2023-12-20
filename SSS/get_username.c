#include "shell.h"

/**
 * get_username - Function to retrieve the username.
 *
 * Return: a pointer to the username,
 *         or root if their is no username.
 */
char *get_username(void)
{
	char *username = NULL;

	username = _getenv("USER=");    /* get the username */

	if (username == NULL)
	{
		username = "root";    /* if their is no username, set it to root */
	}

    printf("%s", username);     /* print the username */

	return (username);
}
