#include "main.h"
/**
 * get_command - Gets the full path to a command.
 * @command: The command to get the full path to.
 * Description:
 * This function searches for the specified command in the directories
 * listed in the "PATH" environment variable and returns the full path
 * to the command. If the command is not found, it returns NULL.
 * @command: Command to get the full path to.
 * Return: the full path to the command or NULL if not found.
 */
char *get_command(char *command)
{
	char *path = NULL;
	char *token, *command_full;
	struct stat st;

	/* Tokenize the "PATH" environment variable */
	token = strtok(path, ":");
	while (token)
	{
		/* Allocate memory for the full path to the command */
		command_full = malloc(strlen(token) + strlen(command) + 2);
		/* Copy the token to the full path */
		strcpy(command_full, token);
		/* Concatenate the token with the command */
		strcat(token, "/");
		strcat(token, command);
		/* Check if the file exists */
		if (stat(token, &st) == 0)
		{
			/* Return the full path to the command */
			return (token);
		}
		/* Free the memory allocated for the full path */
		free(command_full);
		/* Get the next token */
		token = strtok(NULL, ":");
	}
	return (NULL);
}
