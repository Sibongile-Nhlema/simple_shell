#include <header.h>

/**
 * strcspn - determine the length of the initial segment of a string
 * that does not contain any characters from
 * a specified set of characters
 * @str1: first string
 * @str2: second string
 *
 * Return: number of characters in str1 that don't appear in str2
 */

size_t sea_strcspn(const char *str1, const char *str2)
{
	size_t length = 0;
	const char *ptr1 = str1;
	const char *ptr2;

	while (*ptr1 != '\0')
	{
		ptr2 = str2;

		while (*ptr2 != '\0')
		{
			if (*ptr1 == *ptr2)
				return (length);
		ptr2++;
		}
		ptr1++;
		length++;
	}
	return (length);
}

