#include "shell.h"

/**
 * search_executable_in_path - Searches for an executable in the PATH
 * @executable: String executable to search in the PATH
 * Description: Searches for the specified executable in the directories
 * listed in the PATH.
 * Return: Full path to the executable if found, NULL otherwise.
 */
char *search_executable_in_path(char *executable)
{
	char *path_variable = NULL, *delimiter = ":", *full_path = NULL;
	char **path_directories = NULL;
	size_t index = 0, executable_length = 0;
	struct stat st;

	path_variable = get_path_variable();	/* Get the PATH variable */

	/* Split the PATH variable into directories */
	path_directories = splitter(path_variable, delimiter, ':');
	free(path_variable);	/* Free the PATH variable */

	while (path_directories[index])	/* Loop through the directories */
	{
		executable_length = (strlen(executable));
		/* Allocate memory for the full path */
		full_path = malloc((strlen(path_directories[index]) + executable_length + 2)
* sizeof(char));

		strcpy(full_path, path_directories[index]);
		strcat(full_path, "/");
		strcat(full_path, executable);

		if (stat(full_path, &st) == 0)	/* If the file exists */
		{
			break;
		}

		free(full_path);
		full_path = strdup(executable);
		index++;
	}

	free_arguments(path_directories);
	return (full_path);
}

/**
 * get_path_variable - Retrieves the value of the PATH environment variable
 *
 * Description: Retrieves the value of the PATH environment variable.
 * Return: The value of the PATH variable, or NULL if not found.
 */
char *get_path_variable(void)
{
	char *path_variable = NULL, *path_value = NULL;
	size_t index = 0;

	while (environ[index])	/* Loop through the environment variables */
	{
		path_value = malloc(5);	/* Allocate memory for the PATH variable */
		strncpy(path_value, environ[index], 4);	/* Copy the first 4 characters */

		if (strcmp(path_value, "PATH") == 0)	/* If the first 4 characters are PATH */
		{
			free(path_variable);	/* Free the previous value of path_variable */
			path_variable = strdup(environ[index]);	/* Copy the PATH variable */
			break;	/* Break out of the loop */
		}

		index++;
	}

	free(path_value);	/* Free the value of path_value */
	return (path_variable);
}

/**
 * print_environment - Prints the current environment variables
 *
 * Description: Prints the current environment variables.
 * Return: Nothing.
 */
void print_environment(void)
{
	size_t index = 0;

	while (environ[index])	/* Loop through the environment variables */
	{
		printf("%s\n", environ[index]);	/* Print the environment variable */
		index++;
	}
}
