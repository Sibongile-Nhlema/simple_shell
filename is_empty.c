#include "shell.h"

/**
 * checkEmptyInput - Checks if input line is empty
 *
 * @line: A pointer to a string
 *
 * Return: 1 if it's empty, 0 if not
 */
int checkEmptyInput(char *line)
{
	int i, length;

	if (line == NULL || line[0] == '\0')
	{
		return (1);
	}

	while (myCustomIsSpace((unsigned char)line[0])) /*Skip over leading whitespaces*/
	{
		line++;
	}
	if (line[0] == '\0') /*Check if line is empty*/
	{
		return (1);
	}

	length = myCustomStrlen(line);
	for (i = length - 1; i >= 0 && myCustomIsSpace((unsigned char)line[i]); i--) /*Remove trailing whitespaces*/
	{
		line[i] = '\0';
	}
	if (line[0] == '\0') /*Check if line is empty*/
	{
		return (1);
	}

	return (0);
}
