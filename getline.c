#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>

/**
 * main - Entry point of the program
 *
 * This function reads the contents of "/etc/motd" file and
 * prints each line along with its length.
 *
 * Return: EXIT_SUCCESS on success, EXIT_FAILURE on failure
 */
int main(void)
{
	FILE *fp;
	char *line = NULL;
	size_t len = 0;
	ssize_t read;

	/* Open the file for reading */
	fp = fopen("/etc/motd", "r");
	if (fp == NULL)
	{
		perror("Error opening file");
		exit(EXIT_FAILURE);
	}

	/* Read and print each line from the file */
	while ((read = getline(&line, &len, fp)) != -1)
	{
		printf("Received a line of length %zu:\n", read);
		printf("%s", line);
	}

	/* Clean up allocated memory for getline */
	if (line)
		free(line);

	/* Close the file */
	fclose(fp);

	return (EXIT_SUCCESS);
}
