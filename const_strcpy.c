#include "shell.h"

/**
 * const_strcpy - Copies a string into a buffer
 * @destination: A pointer to a buffer
 * @source: A pointer to a string
 * Return: A pointer to destination
 */

char *const_strcpy(char *destination, const char *source)
{
	int i;

	for (i = 0; source[i] != '\0'; i++)
		destination[i] = source[i];

	destination[i] = '\0';
	return (destination);
}
