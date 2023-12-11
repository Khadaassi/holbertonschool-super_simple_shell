#include <stdio.h>
#include <unistd.h>

/**
 * main - PPID
 *
 * Return: Always 0.
 */
int main(void)
{
	pid_t my_pid;
	size_t my_ppid;

	my_pid = getpid();
	my_ppid = getppid();
	printf("%u child of %zu\n", my_pid, my_ppid);
	return (0);
}
