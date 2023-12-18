#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

/**
 * main - Simple shell program that executes commands using fork and execve
 *
 * Description:
 * This program implements a basic shell that repeatedly prompts the user
 * for commands and executes them using fork and execve. It uses getline
 * to read input, tokenizes the input into an array, and then forks a child
 * process to execute the command.
 *
 * Return:
 * Always returns 0.
 */
int main(void)
{
	int status, i = 0;   /* Status of child process and loop counter */
	int n_char;          /* Number of characters read by getline */
	char *buffer = NULL; /* Buffer for getline */
	size_t buffer_size = 0; /* Size of the buffer */
	char *token;         /* Token for strtok */
	char **array;        /* Array to store command and arguments */
	pid_t pid;           /* Process ID */

	/* Infinite loop for shell functionality */
	while (1)
	{
		printf("#cisfun$"); /* Print shell prompt */

		/* Read input from the user using getline */
		n_char = getline(&buffer, &buffer_size, stdin);

		/* Allocate memory for the array to store command and arguments */
		array = malloc(sizeof(char *) * 1024);

		/* Tokenize the input into the array */
		token = strtok(buffer, " \t\n");
		while (token)
		{
			array[i] = token;
			token = strtok(NULL, " \t\n");
			i++;
		}

		array[i] = NULL; /* Set the last element of the array to NULL for execve */

		/* Fork a child process to execute the command */
		pid = fork();
		if (pid == 0)
		{
			/* Child process executes the command using execve */
			if (execve(array[0], array, NULL) == -1)
				perror("execve");
		}
		else
		{
			/* Parent process waits for the child to complete */
			wait(&status);
		}

		i = 0;         /* Reset the loop counter */
		free(array);   /* Free memory allocated for the array */
	}

	return (0); /* Exit program with success status */
}
