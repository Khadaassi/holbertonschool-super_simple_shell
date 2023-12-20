#include "shell.h"

/**
 * free_arguments - Frees memory allocated for an array of strings
 * @arguments: Buffer to be freed
 * Description: Frees the memory allocated for an array of strings.
 * Return: void
 */
void free_arguments(char **arguments)
{
	size_t index = 0;   /* Index for the array */

	if (arguments == NULL)  /* If the buffer is NULL */
	{
		return;
	}

	while (arguments[index])    /* While there are arguments */
	{
		free(arguments[index]);   /* Free the argument */
		index++;
	}

	if (arguments[index] == NULL)   /* If the last position is NULL */
	{
		free(arguments[index]);  /* Free the last position */
	}

	free(arguments);    /* Free the array */
}
