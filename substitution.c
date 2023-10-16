#include "shell.h"

/**
 * handleSubstitution - Handles variable substitution
 *
 * @token: A pointer to a part of the command line
 * @status: The last command's exist status
 *
 * Return: A pointer to the (possibly edited) command line
 */
char *handleSubstitution(char *token, int status)
{
	char pidString[10], statusString[10], *varValue, *modifiedToken = NULL;
	int i = 0, statusCopy = status;
	pid_t pid = getpid();

	if (token[0] == '$')
	{
		if (myCustomStrcmp(token, "$$") == 0)
		{
			intToStr(pidString, pid, i);
			modifiedToken = myCustomStrdup(pidString);
			return (modifiedToken);
		}
		else if (myCustomStrcmp(token, "$?") == 0)
		{
			if (status == 0)
				return (myCustomStrdup("0"));
			else if (status > 0)
			{
				intToStr(statusString, statusCopy, i);
				modifiedToken = myCustomStrdup(statusString);
				return (modifiedToken);
			}
			else
			{
				statusString[i++] = '-';
				statusCopy *= -1;
				intToStr(statusString, statusCopy, i);
				modifiedToken = myCustomStrdup(statusString);
				return (modifiedToken);
			}
		}
		else
		{
			varValue = myCustomGetenv(token + 1);
			if (varValue != NULL)
				modifiedToken = myCustomStrdup(varValue);
		}
	}
	return (modifiedToken);
}
/**
 * reverseString - Reverses a string
 *
 * @string: a pointer to a string
 */
void reverseString(char *string)
{
	size_t length = myCustomStrlen(string);
	int i, j;
	char temp;

	for (i = 0, j = length - 1; i < j; i++, j--)
	{
		temp = string[i];
		string[i] = string[j];
		string[j] = temp;
	}
}
/**
 * intToStr - Converts a number to a string
 *
 * @string: A pointer to a numeral string
 * @number: A number
 * @index: The index to start placing characters
 */
void intToStr(char *string, int number, int index)
{
	while (number > 0)
	{
		string[index++] = (number % 10) + '0';
		number /= 10;
	}
	string[index] = '\0';
	reverseString(string);
}
