#include "shell.h"

/**
 * checkLine - Checks what the command line contains
 *
 * @line: A pointer to the line
 * @status2: A pointer to the status
 */
void checkLine(char *line, int *status2)
{
	if (myCustomStrstr(line, ";"))
	{
		*status2 = splitSeparator(line);
	}

	if (myCustomStrstr(line, "||") || myCustomStrstr(line, "&&"))
	{
		*status2 = splitLogicalLine(line);
	}
}
