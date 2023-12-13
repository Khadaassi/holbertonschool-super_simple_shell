#include <stdio.h>
#include <unistd.h>

/**
 * main - Entry point of the program
 *
 * Description:
 * This function retrieves the process ID (PID) and the parent PID (PPID)
 * using the getpid() and getppid() functions, respectively. It then prints
 * the PID and PPID to the standard output.
 *
 * Return: Always 0 (indicating successful execution).
 */
int main(void)
{
	pid_t my_pid;   /* Variable to store the process ID */
	size_t my_ppid;  /* Variable to store the parent process ID */

	my_pid = getpid();    /* Get the current process ID */
	my_ppid = getppid();  /* Get the parent process ID */

	/* Print the PID and PPID to the standard output */
	printf("%u child of %zu\n", my_pid, my_ppid);

	return (0);  /* Return 0 to indicate successful execution */
}
