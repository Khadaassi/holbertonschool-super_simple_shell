#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

/**
 * main - Executes /bin/ls command in a loop using fork and execve
 *
 * Description:
 * This program uses fork and execve to execute the /bin/ls command with
 * the arguments "-l" and "/tmp" in a loop, creating multiple child processes.
 *
 * Return:
 * Always returns 0.
 */
int main(void)
{
	int i = 0;          /* Loop counter */
	pid_t pid;          /* Process ID */
	int status;         /* Child process status */
	char *args[] = {"/bin/ls", "-l", "/tmp", NULL}; /* Command and arguments */

	/* Loop to create child processes */
	for (i = 0; i < 5; i++)
	{
		/* Fork a child process */
		pid = fork();
		if (pid == -1)
		{
			perror("fork"); /* Print error message if fork fails */
			exit(EXIT_FAILURE); /* Exit with failure status */
		}

		/* Child process */
		if (pid == 0)
		{
			/* Execute /bin/ls command with arguments using execve */
			if (execve(args[0], args, NULL) == -1)
			{
				perror("execve"); /* Print error message if execve fails */
				exit(EXIT_FAILURE); /* Exit child with failure status */
			}
		}
		else
		{
			/* Parent process waits for the child to complete */
			wait(&status);
		}
	}

	exit(EXIT_SUCCESS); /* Exit program with success status */
}
