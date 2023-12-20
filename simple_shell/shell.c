#include "shell.h"

/**
 * main - Entry point for Simple Shell
 * @ac: Argument count
 * @av: Argument vector
 *
 * Description: The main function for the Simple Shell program.
 * Return: Always returns 0.
 */
int main(int ac __attribute__((unused)), char **av)
{
	char *input_line = NULL, *delimiters = {" \t\n"}, *executable_path = NULL;
	char **arguments = NULL;

	signal(SIGINT, signal_handler);	/* Set the signal handler */

	while (1)	/* Infinite loop */
	{
		input_line = read_line();

		if (has_spaces(input_line))	/* If the buffer has spaces */
		{
			free(input_line);	/* Free the buffer */
			continue;
		}

		if (strcmp(input_line, "env\n") == 0)	/* If the buffer is env */
		{
			print_environment();
			free(input_line);
			continue;
		}

		if (strcmp(input_line, "exit\n") == 0)	/* If the buffer is exit */
		{
			free(input_line);
			break;
		}

		arguments = splitter(input_line, delimiters, ' ');	/* Split the buffer */

		if (input_line[0] != '/')	/* If the buffer is not an absolute path */
		{
			executable_path = search_executable_in_path(arguments[0]);	/* Search the executable in the PATH */
			free(arguments[0]);
			arguments[0] = NULL;
			arguments[0] = executable_path;
			executable_path = NULL;
		}

		create_child_process(input_line, arguments, av);
		free_arguments(arguments);
		free(input_line);
	}

	return (0);
}
