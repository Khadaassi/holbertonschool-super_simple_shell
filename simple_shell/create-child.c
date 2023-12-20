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
	pid_t child_pid;
	int status = 0;

	child_pid = fork();

	if (!child_pid)
	{
		if (execve(args[0], args, NULL) == -1)
		{
			printf("%s: No such file or directory\n", av[0]);
			free_arguments(args);
			free(line);
			exit(EXIT_FAILURE);
		}
	}
	else if (child_pid < 0)
	{
		perror("process error");
		free_arguments(args);
		free(line);
	}
	else
	{
		waitpid(-1, &status, 0);
		if (WIFEXITED(status))
			WEXITSTATUS(status);
	}
	free_arguments(args);
	free(line);
}
