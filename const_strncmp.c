#include "shell.h"

/**
 * const_strncmp - compares strings
 * @string1: first string
 * @string2: second string
 * @number: specified length
 * Return: difference between string1 and string2
 */

int const_strncmp(char *string1, const char *string2, size_t number)
{
	while (number && *string1 && *string2 && (*string1 == *string2))
	{
		string1++;
		string2++;
		number--;
	}
	if (number == 0)
		return (0);
	else
		return (*string1 - *string2);
}
