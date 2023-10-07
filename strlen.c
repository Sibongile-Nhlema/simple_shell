#include "shell.h"

/**
 * myCustomStrlen - Finds the length of a given string
 *
 * @string: A pointer to a string
 *
 * Return: The length of the string
 */
int myCustomStrlen(char *string)
{
	int length = 0;

	while (string[length] != '\0')
		length++;

	return (length);
}
