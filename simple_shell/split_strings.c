#include "main.h"
/**
 * split_string - Splits a string into tokens.
 * @buffer: The string to split.
 * @del: The delimiter used to split the string.
 * Description: This function splits a string into tokens using the specified
 * delimiter.
 * It returns an array of tokens.
 * @buffer: String to split.
 * @del: Delimiter used to split the string.
 * Return: returns an array of tokens.
 */

char **split_string(char *buffer, char *del)
{
	char *token;
	char **tokens; /* Stores the tokens */
	int index = 0; /* Stores the index of the current token */

	/* Tokenize the input string */
	tokens = malloc(sizeof(char *) * 1024); /* Allocate memory for the tokens */
	token = strtok(buffer, del); /* Get the first token */
	/* Store the tokens in the tokens array */
	while (token)
	{
		tokens[index] = token; /* Store the token in the tokens array */
		token = strtok(NULL, del); /* Get the next token */
		index++; /* Increment the index of the current token */
	}
	tokens[index] = NULL; /* Set the last element of the array to NULL */
	return (tokens); /* Return the array of tokens */

	/* Print the tokens (for testing purposes) */
	for (index = 0; tokens[index]; index++)
		printf("%s\n", tokens[index]);

	/* Return the array of tokens */
	return (tokens);
}
