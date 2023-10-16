#include "shell.h"

/**
 * remove_comments_from_line - removes comments from the commandline
 * @string: array of arguments
 *
 * Return: nothing
 */

void remove_comments_from_line(char *string)
{
	int r;

	for (r = 0; string[r] != '\0'; r++)
	{
		if ((r == 0 && string[r] == '#') ||
				(r > 0 && string[r] == '#' && string[r - 1] == ' '))
		{
			string[r] = '\0';
			break;
		}
	}
}
