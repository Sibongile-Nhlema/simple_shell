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
	if (myCustomStrcmp(token, "exit") == 0) /*Implement exit*/
	{
		tokens = implementExit(token, lineCopy);
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
/**
 * splitLogicalLine - Splits a line with logical operators
 *
 * @line: A pointer to the line
 *
 * Return: 0 on success, nonzero on failure
 */
int splitLogicalLine(char *line)
{
	char token[1024], **tokens;
	int ret, i = 0, j = 0;

	while (line[i] != '\0')
	{
		if ((line[i] == '&' && line[i + 1] == '&')
				|| (line[i] == '|' && line[i + 1] == '|'))
		{
			token[j] = '\0';
			tokens = splitLine(token);

			ret = execute_command(tokens, token);
			freeTokens(tokens);
			j = 0;

			if (ret == 0 && line[i] == '|' && line[i + 1] == '|')
			{
				break;
			}
			if (ret != 0 && line[i] == '&' && line[i + 1] == '&')
			{
				break;
			}
			i += 2;
		}
		token[j] = line[i];
		i++, j++;
		if (line[i] == '\0')
		{
			token[j] = '\0';
			tokens = splitLine(token);
			ret = execute_command(tokens, token);
			freeTokens(tokens);
		}
	}
	return (ret);
}
