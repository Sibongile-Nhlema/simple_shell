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
	if (status != NULL && myCustomAtoi(status) > 0)
	{
		tokens = positiveStatusHandler(status, lineCopy, token);
		return (tokens);
	}
	if (status != NULL && myCustomAtoi(status) < 0)
	{
		tokens = negativeStatusHandler(status, lineCopy, token);
		return (tokens);
	}
	if (status != NULL && myCustomAtoi(status) == 0)
	{
		tokens = stringStatusHandler(status, lineCopy, token);
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
/**
 * findExitStatus - Finds the exit status when exit built-in is used
 *
 * @tokens: An array of command line strings
 * @line: A pointer to the command line
 * @argv: An array of command line arguments
 *
 * Return: The exit status
 */
int findExitStatus(char **tokens, char *line, char **argv)
{
	int status;

	if (tokens[1] != NULL && myCustomAtoi(tokens[1]) > 0)
	{
		status = myCustomAtoi(tokens[1]);
		free(line);
		/* freeTokens(tokens); */
		return (status);
	}
	if (tokens[1] != NULL && myCustomAtoi(tokens[1]) < 0)
	{
		free(line);
		negativeExitError(argv[0], tokens[1]);
		/* freeTokens(tokens); */
		return (2);
	}
	if (tokens[1] != NULL && myCustomAtoi(tokens[1]) == 0)
	{
		free(line);
		stringExitError(argv[0], tokens[1]);
		/* freeTokens(tokens); */
	}
	return (2);
}
/**
 * positiveStatusHandler - Handles exit with a positive number
 *
 * @status: A pointer to the status string
 * @lineCopy: A pointer to a copy of the command line
 * @token: A pointer to the "exit" string
 *
 * Return: An array of strings containing "exit" and a status,
 * or NULL
 */
char **positiveStatusHandler(char *status, char *lineCopy, char *token)
{
	char **tokens;

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
/**
 * negativeStatusHandler - Handles exit with a negative number
 *
 * @status: A pointer to the status string
 * @lineCopy: A pointer to a copy of the command line
 * @token: A pointer to the "exit" string
 *
 * Return: An array of strings containing "exit" and a status,
 * or NULL
 */
char **negativeStatusHandler(char *status, char *lineCopy, char *token)
{
	char **tokens;

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
/**
 * stringStatusHandler - Handles exit with a string
 *
 * @status: A pointer to the status string
 * @lineCopy: A pointer to a copy of the command line
 * @token: A pointer to the "exit" string
 *
 * Return: An array of strings containing "exit" and a status,
 * or NULL
 */
char **stringStatusHandler(char *status, char *lineCopy, char *token)
{
	char **tokens;

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
