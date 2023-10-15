#include "shell.h"

/**
 * myCustomStrstr - Finds the first occurrence of
 * the substring substring in a string
 * @string: A pointer to a string
 * @substring: A pointer to a substring
 * Return: A pointer to the start of the substring substring,
 * or NULL if not substring.
 */
char *myCustomStrstr(char *string, char *substring)
{
	int i, j, substringLen = 0;

	while (substring[substringLen] != '\0')
	{
		substringLen++;
	}

	for (i = 0; string[i] != '\0'; i++)
	{
		for (j = 0; substring[j] != '\0' && string[i + j] == substring[j]; j++)
		{
			continue;
		}
		if (substring[j] == '\0')
		{
			return (string + i);
		}
	}

	return (NULL);
}
