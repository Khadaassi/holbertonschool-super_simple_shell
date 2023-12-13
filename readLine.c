#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * splitter - Splits a string into an array of tokens.
 * @str: The input string to be split.
 *
 * Return: An array of tokens.
 */
char **splitter(char *str)
{
	char *token, **tokens = NULL;
	int index = 0;

	/* Tokenize the input string */
	token = strtok(str, " \t\n");
	while (token != NULL)
	{
		index++;

		/* Resize the tokens array to accommodate a new token */
		tokens = realloc(tokens, index * sizeof(char *));
		if (tokens == NULL)
		{
			perror("realloc");
			exit(EXIT_FAILURE);
		}

		/* Store the token in the tokens array */
		tokens[index - 1] = token;

		/* Get the next token */
		token = strtok(NULL, " \t\n");
	}

	/* Print the tokens (for testing purposes) */
	for (index = 0; tokens[index]; index++)
		printf("%s\n", tokens[index]);

	/* Return the array of tokens */
	return (tokens);
}

int main(int ac, char **av)
{
	char *buffer = NULL, **tokens;
	size_t sizeBuffer = 0;
	int numberChar = 0;

	printf("$ ");

	/* Read input from the user */
	numberChar = getline(&buffer, &sizeBuffer, stdin);
	if (numberChar == EOF)
	{
		perror("getline");
		exit(EXIT_FAILURE);
	}

	/* Remove the newline character at the end of the input */
	buffer[numberChar - 1] = '\0';

	/* Call the splitter function to tokenize the input */
	tokens = splitter(buffer);

	/* Free allocated memory */
	free(buffer);
	free(tokens);

	return (0);
}
