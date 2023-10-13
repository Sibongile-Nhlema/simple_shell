#include "shell.h"

/**
 * myCustomStrncmp - Copies a number of characters from a string
 *
 * @string1: A pointer to the destination string
 * @string2: A pointer to the source string
 * @n: Number of characters to compare
 *
 * Return: 0 if the characters are indentical, nonzero if not
 */
int myCustomStrncmp(const char *string1, const char *string2, int n)
{
	int i;

	for (i = 0; i < n && string2[i] != '\0'; i++)
	{
		if (string1[i] != string2[i])
			return (string1[i] - string2[i]);
	}

	return (0);
}
