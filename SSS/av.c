#include <stdio.h>

/**
 * main - Entry point of the program
 * @ac: Number of command-line arguments
 * @av: Array of command-line argument strings
 *
 * Return: Always 0 (success)
 */
int main(int ac, char **av)
{
	int i = 0;

	/* Iterate through the command-line arguments */
	while (av[i])
	{
		/* Print each command-line argument */
		printf("%s\n", av[i]);
		i++;
	}

	return (0);
}
