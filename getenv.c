#include "shell.h"

extern char **environ;

/**
 * myCustomGetenv - Searches the environment list to find the var name
 *
 * @varName: A pointer to the name to find
 *
 * Return: A pointer to the value in the environment, or NULL if no match.
 */
char *myCustomGetenv(char *varName)
{
	char **environment = environ, *token;

	while (*environment)
	{
		token = strtok(*environment, "=");
		if (myCustomStrcmp(varName, token) == 0)
		{
			token = strtok(NULL, "=");
			return (token);
		}
		environment++;
	}

	return (NULL);
}
