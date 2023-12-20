#include "shell.h"

/**
 * signal_handler - Handles signals in Simple Shell
 * @signal_number: Signal number
 * Description: Handles the SIGINT signal for Ctrl + C.
 * Return: Nothing.
 */
void signal_handler(int signal_number)
{
	if (signal_number == SIGINT)	/* Ctrl + C */
	{
		printf("welcometohell$ ");	/* Print prompt */
	}
}

/**
 * count_separator - Counts separators in a string for Simple Shell
 * @line: Buffer to count separators
 * @separator: Separator character
 * Description: Counts the occurrences of the separator character in a string.
 * Return: Number of separators found.
 */
int count_separator(char *line, char separator)
{
	int count = 0, index = 0;

	while (line[index])	/* While not end of string */
	{
		if (line[index] == separator)	/* If separator found */
			count++;
		index++;
	}
	count++;

	return (count);
}

/**
 * has_spaces - Validates spaces, tabs, and line breaks in Simple Shell
 * @input: String from input
 * Description: Checks if the string contains only spaces, tabs, line breaks.
 * Return: 1 if no spaces, tabs, or line breaks found, 0 otherwise.
 */
int has_spaces(char *input)
{
	int index = 0, flag = 1, length = 0;	/* Flag = 1 if no spaces found */

	length = strlen(input);	/* Get length of string */

	while (input[index] == ' ' || input[index] == '\n' || input[index] == '\t')
		index++;

	if (index != length)	/* If index is not equal to length */
		flag = 0;	/* Spaces found */

	return (flag);
}
