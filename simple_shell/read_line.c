#include "shell.h"

/**
 * read_line - C - Simple Shell
 * Description: Read a line from standard input.
 * Return: Pointer to the line.
*/
char *read_line(void)
{
	char *input_line = NULL;    /* Pointer to the line */
	size_t len = 0;             /* Length of the line */
	ssize_t read = 0;           /* Number of characters read */
	int is_terminal = 0;

	is_terminal = isatty(STDIN_FILENO); /* Check if the input is from a terminal*/
	if (is_terminal == 1)               /* If the input is from a terminal */
		printf("#welcometohell$ ")      /* Print the prompt */

	read = getline(&input_line, &len, stdin);   /* Read the line */

	if (read == EOF)
	{
		/*printf("\n");*/
		free(input_line);       /* Free the buffer */
		exit(EXIT_FAILURE);     /* Exit with failure */
	}
	return (input_line);        /* Return the line */
}
