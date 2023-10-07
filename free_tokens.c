#include "shell.h"

/**
 * freeTokens - Frees the tokens array
 * @tokens: command  and arguments inputted
 */
void freeTokens(char **tokens)
{
	int i;

	if (tokens == NULL)
		return;


	for (i = 0; tokens[i] != NULL; i++)
	{
		if (myCustomStrcmp(tokens[i], "exit") == 0)
		{
			free(tokens[i]);
			break;
		}
		free(tokens[i]);
	}
	free(tokens);
}
