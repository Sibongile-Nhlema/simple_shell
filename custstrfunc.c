#include "shell.h"

/**
 * myCustomStrcat - Concatenates two given strings
 *
 * @destination: Main string
 * @source: String to be appended to destination
 *
 * Return: A pointer to the resulting string destination
 */
char *myCustomStrcat(char *destination, char *source)
{
	int destinationLength, i;

	destinationLength = myCustomStrlen(destination);

	for (i = 0; source[i] != '\0'; i++)
	{
		destination[destinationLength + i] = source[i];
	}

	destination[destinationLength + i] = '\0';

	return (destination);
}

/**
 * myCustomStrchr - Finds a character in a string
 *
 * @string: A pointer to a string
 * @character: A character
 *
 * Return: A pointer to the first occurrence of the character
 * in the string, NULL if the character isn't found
 */
char *myCustomStrchr(char *string, char character)
{
	int j;

	for (j = 0; string[j] != '\0'; j++)
	{
		if (string[j] == character)
		{
			return (string + j);
		}
	}
	if (character == '\0')
	{
		return (string + j);
	}

	return (NULL);
}

/**
 * myCustomStrcmp - The function compares 2 strings
 * @str1: A pointer to the first string
 * @str2: A pointer to the second string
 * Return: 0 if identical, nonzero if not
 */
int myCustomStrcmp(char *str1, char *str2)
{
	int j;

	for (j = 0; str1[j] != '\0'; j++)
	{
		if (str1[j] != str2[j])
			return (str1[j] - str2[j]);
	}
	if (sizeof(str1) > sizeof(str2))
		return ((int)(str1[j]));
	else if (sizeof(str1) < sizeof(str2))
		return ((int)(str2[j]));
	else
		return (0);
}

/**
 * myCustomStrcpy - Copies a string into a buffer
 *
 * @destination: A pointer to a buffer
 * @source: A pointer to a string
 *
 * Return: A pointer to destination
 */
char *myCustomStrcpy(char *destination, char *source)
{
	int i;

	for (i = 0; source[i] != '\0'; i++)
		destination[i] = source[i];

	destination[i] = '\0';
	return (destination);
}

/**
 * myCustomStrdup - Duplicates an existing string
 *
 * @string: A pointer to a string
 *
 * Return: A pointer to the duplicate string, or NULL if it fails,
 * or if string is NULL
 */
char *myCustomStrdup(char *string)
{
	char *duplicatedString;
	int length, i;

	if (string == NULL)
		return (NULL);

	length = myCustomStrlen(string);

	duplicatedString = malloc((length + 1) * sizeof(char));

	if (duplicatedString == NULL)
		return (NULL);

	for (i = 0; i < length; i++)
		duplicatedString[i] = string[i];

	duplicatedString[i] = '\0';

	return (duplicatedString);
}
