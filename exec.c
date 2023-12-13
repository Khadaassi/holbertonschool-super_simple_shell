#include <stdio.h>
#include <unistd.h>

/**
 * main - Example of execve usage
 *
 * This program demonstrates the use of execve to execute the /bin/ls command
 * with the arguments "-l" and "/usr/".
 *
 * Return: Always 0.
 */
int main(void)
{
	char *argv[] = {"/bin/ls", "-l", "/usr/", NULL};

	/* Print a message before execve */
	printf("Before execve\n");

	/* Execute the /bin/ls command with arguments using execve */
	if (execve(argv[0], argv, NULL) == -1)
	{
		/* Handle errors in execve */
		perror("Error:");
	}

	/* This line will not be reached if execve is successful */
	printf("After execve\n");

	return (0);
}
