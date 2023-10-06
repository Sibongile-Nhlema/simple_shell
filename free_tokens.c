#include "shell.h"

/**
 * freeTokens - Frees the tokens array
 * @tokens: command  and arguments inputted
 */
void freeTokens(char **tokens)
{
	int i;

	for (i = 0; tokens[i] != NULL; i++)
	{
		free(tokens[i]);
	}
	free(tokens);
}
