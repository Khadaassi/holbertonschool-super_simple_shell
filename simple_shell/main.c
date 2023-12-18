/**
 * main - Entry point
 * @ac: The number of arguments passed to the program.
 * @av: An array of pointers to the arguments.
 * @env: An array of pointers to the environment variables.
 * Return: Always 0
 */
*/
int main(int ac, char **av, char **env)
{
	{
		char *buffer = NULL; /* Buffer to store the input string */
		size_t sizeBuffer = 0; /* Size of the buffer */
		char *cmd; /* Stores the full path to the command */

	char **args; /* Stores the arguments passed to the command */
	pid_t pid; /* Stores the process ID of the child process */
	int status, n_chars; /* Stores the status of the child process */

	/* Get the value of the "PATH" environment variable */
	while (1)
	{
		/* Print the prompt */
		printf("$ ");
		/* Read input from the user */
		n_chars = getline(&buffer, &sizeBuffer, stdin);
		/* Remove the newline character at the end of the input */
		if (n_chars == -1)
		{
			printf("\n"); /* Print a new line */
			exit(1); /* Exit the program */
		}
		/* Fork a child process */
		args = split_string(buffer, " \t\n");
		/* Check if the user entered the "exit" command */
		if (strcmp(args[0], "exit") == 0)
		{
			free(buffer); /* Free the memory allocated for the buffer */
			free(args); /* Free the memory allocated for the tokens */
			exit(0); /* Exit the program */
		}
		/* Fork a child process */
		if (pid == 0)
		{
			cmd = get_command(args[0]); /* Get the full path to the command */
			/* Execute the command */
			if (cmd)
			{
				execve(cmd, args, env);
			}
			/* Print an error message if the command is not found */
			else
			{
				printf("%s: command not found\n", args[0]);
				exit(0);
			}
		}
		/* Wait for the child process to terminate */
		else
		{
			wait(&status);
		}
		return (0);
	}
}
