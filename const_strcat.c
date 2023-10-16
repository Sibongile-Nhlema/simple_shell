#include "shell.h"

/**
 * const_strcat - Concatenates two given strings
 * @destination: Main string
 * @source: String to be appended to destination
 * Return: A pointer to the resulting string destination
 */

char *const_strcat(char *destination, const char *source)
{
	int destinationLength, i;

	destinationLength = myCustomStrlen(destination);
	for (i = 0; source[i] != '\0'; i++)
		destination[destinationLength + i] = source[i];

	destination[destinationLength + i] = '\0';
	return (destination);
}
