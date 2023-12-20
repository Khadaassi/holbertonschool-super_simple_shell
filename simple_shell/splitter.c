#include "shell.h"
/**
 * splitter - Tokenizes a buffer in Simple Shell
 * @input_line: Buffer to tokenize
 * @delimiters: Delimiter characters
 * @separator: Separator
 *
 * Description: Tokenizes a buffer into an array of strings.
 * Return: An array of strings containing the tokens.
 */
char **splitter(char *input_line, char *delimiters, char separator)
{
	int token_count = 0, index = 0;	/* Number of tokens and index */
	char **arguments = NULL;		/* Array of tokens */
	char *token = NULL;				/* Pointer to a token */

	token_count = count_separator(input_line, separator);	/* Count the number of tokens */
	arguments = malloc((token_count + 1) * sizeof(char *));	/* Allocate memory for the array */

	if (input_line[0] == '\n')	/* If the buffer is a new line */
	{
		arguments[0] = strdup("\n");	/* Allocate memory for the token */
		arguments[1] = NULL;		/* Set the last position to NULL */
	}
	else	/* If the buffer is not a new line */
	{
		if (arguments == NULL)	/* If the allocation fails */
		{
			/*free(input_line);*/
			/*free_arg(arguments);*/
			return (NULL);
		}

		token = strtok(input_line, delimiters);	/* Get the first token */
		index = 0;	/* Initialize the index */

		while (token != NULL)	/* While there are tokens */
		{
			arguments[index] = strdup(token);	/* Allocate memory for the token */

			if (arguments[index] == NULL)	/* If the allocation fails */
			{
				/*free_arg(arguments);*/
				return (NULL);
			}

			token = strtok(NULL, delimiters);	/* Get the next token */
			index++;
		}

		arguments[index] = NULL;	/* Set the last position to NULL */
	}

	return (arguments);
}
