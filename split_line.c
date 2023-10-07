#include "shell.h"

/**
 * splitLine - Splits a line into tokens
 * @line: commands on commandline
 *
 * Return: An array of pointers to tokens
 */
char **splitLine(char *line)
{
	char *lineCopy, *token, **tokens;
	int i;

	lineCopy = myCustomStrdup(line);
	token = strtok(line, DELIM);
	if (myCustomStrcmp(token, "exit") == 0) /*Implement exit built-in*/
	{
		tokens = malloc(sizeof(char *));
		if (tokens == NULL)
		{
			free(lineCopy);
			perror("Error: Failed to allocate memory.\n");
			return (NULL);
		}
		tokens[0] = myCustomStrdup(token);
		free(lineCopy);
		return (tokens);
	}
	i = 0;
	while (token != NULL) /*Count the tokens*/
	{
		i++;
		token = strtok(NULL, DELIM);
	}
	tokens = malloc((i + 1) * sizeof(char *));
	if (tokens == NULL)
	{
		free(lineCopy);
		return (NULL);
	}
	i = 0;
	token = strtok(lineCopy, DELIM); /*Add tokens to the tokens array*/
	while (token != NULL)
	{
		tokens[i] = myCustomStrdup(token);
		i++;
		token = strtok(NULL, DELIM);
	}
	tokens[i] = NULL;

	free(lineCopy);
	return (tokens);
}
