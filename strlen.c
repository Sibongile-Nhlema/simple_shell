#include "header.h"

/**
 * sea_strlen - calculates the length of a string
 * @string: string inputted by user
 */

ssize_t sea_strlen(const char *str)
{
	ssize_t length = 0;

	while (*str != '\0')
	{
		length++;
		str++;
	}
	return (length);
}
