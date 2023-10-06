#include "shell.h"

/**
 * splitLine - Splits a line into tokens
 *
 * Return: An array of pointers to tokens
 */
char **splitLine(char *line)
{
	char *lineCopy, *token, **tokens;
	int i;

	lineCopy = strdup(line);
	token = strtok(line, DELIM); /*Count the tokens*/
	i = 0;
	while (token != NULL)
	{
		i++;
		token = strtok(NULL, DELIM);
	}
	tokens = malloc((i + 1) * sizeof(char *));
	if (tokens == NULL)
	{
		return (NULL);
	}
	i = 0;
	token = strtok(lineCopy, DELIM); /*Add tokens to the tokens array*/
	while (token != NULL)
	{
		tokens[i] = strdup(token);
		i++;
		token = strtok(NULL, DELIM);
	}
	tokens[i] = NULL;

	free(lineCopy);
	return (tokens);
}
