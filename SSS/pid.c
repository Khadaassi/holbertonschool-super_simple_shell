#include <stdio.h>
#include <unistd.h>

/**
 * main - Entry point of the program
 *
 * Description: This program prints the process ID (PID) using getpid().
 *
 * Return: Always 0 (success)
 */
int main(void)
{
	/* Declare a variable to store the process ID */
	pid_t my_pid;

	/* Get the process ID using getpid() */
	my_pid = getpid();

	/* Print the process ID to the standard output */
	printf("%u\n", my_pid);

	/* Return 0 to indicate successful execution */
	return (0);
}
