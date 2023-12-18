#include <stdio.h>
#include <unistd.h>

/**
 * main - Example of fork usage
 *
 * This program demonstrates the use of fork to create a child process.
 * The parent process prints messages before and after fork, and the child
 * process prints its own process ID (PID).
 *
 * Return: Always 0.
 */
int main(void)
{
	pid_t my_pid;
	pid_t pid;

	/* Print a message before the fork */
	printf("Before fork\n");

	/* Create a child process using fork */
	pid = fork();

	/* Check for errors in the fork process */
	if (pid == -1)
	{
		perror("Error:");
		return (1);
	}

	/* Print a message after the fork */
	printf("After fork\n");

	/* Get the process ID of the current process */
	my_pid = getpid();

	/* Print the process ID of the current process */
	printf("My pid is %u\n", my_pid);

	return (0);
}
