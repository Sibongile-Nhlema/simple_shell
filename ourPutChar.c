#include "shell.h"

/**
 * ourPutChar - writes a char to stdout
 * @c: char
 *
 * Return: 1 on sucess, -1 on error
 */

int ourPutChar(char c)
{
	static int k;
	static char buffer[1024];

	if (c == -1 || k >= 1024)
	{
		write(1, buffer, k);
		k = 0;
	}
	if (c != -1)
	{
		buffer[k++] = c;
	}
	return (1);
}

