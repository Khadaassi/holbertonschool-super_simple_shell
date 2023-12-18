#include "main.h"
/**
 * print_env - Print the environment variables.
 *
 * @environ: An array of pointers to the environment variables.
 *
 */
void print_env(char **environ)
{
	unsigned int i = 0;

	for (i = 0; environ[i] != NULL; i++)
	{
		printf("%s\n", environ[i]);
	}
}
