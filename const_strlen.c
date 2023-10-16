#include "shell.h"

/**
 * const_strlen - finds the length of a constant string
 * @string: pointer to a string
 * Return: length of string
 */

int const_strlen(const char *string)
{
	int length = 0;

	while (string[length] != '\0')
		length++;
	return (length);
}
