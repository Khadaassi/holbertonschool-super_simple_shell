#include "shell.h"

/**
 * create_child_process - Creates a child process in Simple Shell
 * @line: Received buffer
 * @args: Buffer arguments
 * @av: Argument vector
 *
 * Description: Creates a child process and executes a command.
 * Return: Nothing.
 */
void create_child_process(char *line, char **args, char **av)
{
	pid_t child_pid;	/* Child process ID */
	int status = 0;	/* Child process status */

	child_pid = fork();	/* Fork a child process */

	if (!child_pid)
	{
		/* Execute the command with the arguments */
		if (execve(args[0], args, NULL) == -1)
		{
			printf("%s: No such file or directory\n", av[0]);	/* Print error message */
			free_arguments(args);	/* Free the arguments */
			free(line);	/* Free the buffer */
			exit(EXIT_FAILURE);	/* Exit with failure */
		}
	}
	else if (child_pid < 0)	/* If the fork fails */
	{
		perror("process error");	/* Print error message */
		free_arguments(args);	/* Free the arguments */
		free(line);	/* Free the buffer */
		exit(EXIT_FAILURE);	/* Exit with failure */
	}
	else	/* Parent process */
	{
		wait(&status);	/* Wait for the child to complete */
	}
	free_arguments(args);	/* Free the arguments */
	free(line);	/* Free the buffer */
}
