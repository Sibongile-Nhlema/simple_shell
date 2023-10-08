#include "shell.h"

/**
 * myCustomAtoi - Changes a string into an integer
 *
 * @string: A pointer to a string
 *
 * Return: An integer
 */
int myCustomAtoi(char *string)
{
	int sign, digit;
	unsigned int result = 0;

	sign = 1;
	while (*string != '\0' && (*string < '0' || *string > '9'))
	{
		if (*string == '-')
		{
			sign = -sign;
		}
		string++;
	}
	while (*string >= '0' && *string <= '9')
	{
		digit = *string - '0';

		result = (result * 10) + digit;
		string++;
	}

	if (sign == -1)
	{
		return (result * sign);
	}
	else
	{
		return (result);
	}
}
