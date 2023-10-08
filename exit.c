#include "shell.h"

/**
 * implementExit - Implements the exit built-in
 *
 * @token: A pointer to the first argument in the line
 * @lineCopy: A pointer to a copy of the line
 *
 * Return: An array of pointers to strings
 */
char **implementExit(char *token, char *lineCopy)
{
	char *status, **tokens;

	status = strtok(NULL, DELIM);
	if (status != NULL && myCustomAtoi(status))
	{
		tokens = malloc(sizeof(char *) * 3);
		if (tokens == NULL)
		{
			free(lineCopy);
			perror("Error: Failed to allocate memory.\n");
			return (NULL);
		}
		tokens[0] = myCustomStrdup(token);
		tokens[1] = myCustomStrdup(status);
		tokens[2] = NULL;
		free(lineCopy);
		return (tokens);
	}
	tokens = malloc(sizeof(char *) * 2);
	if (tokens == NULL)
	{
		free(lineCopy);
		perror("Error: Failed to allocate memory.\n");
		return (NULL);
	}
	tokens[0] = myCustomStrdup(token);
	tokens[1] = NULL;
	free(lineCopy);
	return (tokens);
}
