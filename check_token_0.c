#include "shell.h"

/**
 * checkTokens - Checks the command in the tokens array
 *
 * @tokens: An array of command tokens
 * @argv: An array of command line arguments
 * @line: A pointer to the command line
 * @status2: A pointer to the status
 */
void checkTokens(char **tokens, char **argv, char *line, int *status2)
{
	if (strcmp(tokens[0], "cd") == 0)
	{
		implementCdCommand(tokens, argv);
	}
	if (strcmp(tokens[0], "env") == 0)
	{
		printEnvironment();
	}
	if (myCustomStrcmp(tokens[0], "setenv") == 0)
	{
		if (tokens[1] != NULL)
		{
			myCustomSetenv(tokens[1], tokens[2], 1);
		}
	}
	if (myCustomStrcmp(tokens[0], "unsetenv") == 0)
	{
		if (tokens[1] != NULL)
		{
			myCustomUnsetenv(tokens[1]);
		}
	}
	if (myCustomStrcmp(tokens[0], "exit") == 0)
	{
		if (tokens[1] != NULL && (myCustomAtoi(tokens[1]) > 0 ||
					myCustomAtoi(tokens[1]) < 0 ||
					myCustomAtoi(tokens[1]) == 0))
		{
			*status2 = findExitStatus(tokens, line, argv);
		}
	}
	if (tokens == NULL)
	{
		free(line);
	}
}
