#include "header.h"

/**
 * sea_strtok - splits string into words
 * @str: string to be tokenised
 * @delim: delimiter (seperates the tokens)
 *
 * Return: split words
 */

char *sea_strtok(char *str, const char *delim)
{
	static char* current = NULL; /*position of string*/
	char *token;

	if (str != NULL)
		current = str;

	if (current == NULL || *current == '\0') /*error handling*/
		return (NULL);

	token = current; /*if there are more strings to be extracted*/
	while (*current != '\0')
	{
		if (*current == *delim) /*replace delim with NULL char*/
		{
			*current = '\0';
			current++;
			return (token);
		}
		current++;
	}

	if (token == current) /*no more tokens found*/
		return (NULL);

	return (token);
}
