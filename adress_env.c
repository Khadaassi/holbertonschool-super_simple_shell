#include <stdio.h>

/**
 * main - Entry point of the program.
 * @ac: The number of command-line arguments.
 * @av: An array of strings representing the command-line arguments.
 * @env: An array of strings representing the environment variables.
 *
 * Description:
 * This program demonstrates the usage of environment variables by
 * printing the addresses of the environment variables provided as arguments.
 *
 * Return: 0 on successful execution.
 */
int main(int ac, char **av, char **env)
{
	extern char **environ;

	/* Print the address of the 'env' parameter */
	printf("Address of 'env' parameter: %p\n", (void *)env);

	/* Print the address of the 'environ' external variable */
	printf("Address of 'environ' external variable: %p\n", (void *)environ);

	return (0);
}
