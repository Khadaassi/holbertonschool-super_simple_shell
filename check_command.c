#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>

/**
 * check_command - Checks if a command exists in the system's PATH.
 * @command: The command to check.
 *
 * Description:
 * This function checks if the given command exists in the system's PATH
 * and prints whether it is found or not found.
 *
 * Parameters:
 * @command: The command to be checked for existence.
 */
void check_command(char *command)
{
	/* Check if the command exists in the system's PATH */
	if (access(command, F_OK) == 0)
		printf("%s: FOUND\n", command);
	else
		printf("%s: NOT FOUND\n", command);
}

/**
 * main - Simple shell-like program that checks for the existence of commands.
 *
 * Description:
 * This program implements a simple shell-like interface where the user can
 * input the 'which' command followed by a list of commands to check their
 * existence in the system's PATH. It prints whether each command is found or
 * not.
 * Return:
 * Always returns 0.
 */
int main(void)
{
	char *buffer = NULL;    /* Buffer to store user input */
	size_t buffer_size;     /* Size of the buffer */
	ssize_t chars;          /* Number of characters read by getline */
	char *token;            /* Token to store each word from user input */

	/* Infinite loop for shell-like functionality */
	while (1)
	{
		printf("#cisfun$ ");

		/* Read input from the user using getline */
		chars = getline(&buffer, &buffer_size, stdin);

		/* Tokenize the input to extract individual words */
		token = strtok(buffer, " \t\n");

		/* Check if the first token is 'which' */
		if (strcmp(token, "which") == 0)
		{
			/* Move to the next token (the command to check) */
			token = strtok(NULL, " \t\n");

			/* Loop through each token and check its existence */
			while (token)
			{
				check_command(token);
				token = strtok(NULL, " \t\n");
			}
		}
		else
		{
			/* Print an error message if the first token is not 'which' */
			printf("Command not found\n");
		}
	}

	return (0);
}
