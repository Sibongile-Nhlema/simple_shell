#include "shell.h"

/**
 * splitLine - Splits a line into tokens
 *
 * @line: commands on commandline
 * @status: The last command's exit status
 *
 * Return: An array of pointers to tokens
 */
char **splitLine(char *line, int status)
{
	char *lineCopy, *token, **tokens, *modifiedToken = NULL;
	int i;

	lineCopy = myCustomStrdup(line);
	token = strtok(line, DELIM);
	if (myCustomStrcmp(token, "exit") == 0) /*Implement exit*/
		return (implementExit(token, lineCopy));
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
		if (token[0] == '$')
		{
			modifiedToken = handleSubstitution(token, status);
			tokens[i] = myCustomStrdup(modifiedToken);
		}
		else
			tokens[i] = myCustomStrdup(token);
		i++;
		token = strtok(NULL, DELIM);
	}
	tokens[i] = NULL;
	if (lineCopy != NULL)
		free(lineCopy);
	if (modifiedToken != NULL)
		free(modifiedToken);
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
			tokens = splitLine(token, 0);

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
			tokens = splitLine(token, 0);
			ret = execute_command(tokens, token);
			freeTokens(tokens);
		}
	}
	return (ret);
}

/**
 * separator - splits line with semi colon
 * @line: pointer to the line
 * Return: 0 on success, -1 on failure
 */

int separator(char *line)
{
	char token[1024], **tokens;
	int ret = 0, i = 0, j = 0;
	int command_ended_with_semicolon = 0;

	while (line[i] != '\0')
	{
		if (line[i] == ';' /*&& line[i + 1] == '\0'*/)
		{
			token[j] = '\0';
			if (token[0] != '\0')
			{
				tokens = splitLine(token, 0);
				if (tokens != NULL)
				{
					ret = execute_command(tokens, token);
					freeTokens(tokens);
				}
			}
			command_ended_with_semicolon = 1;
			if (command_ended_with_semicolon)
				break;
			j = 0;
			i++;
		}
		if (line[i] == ';')
		{
			token[j] = '\0';
			if (token[0] != '\0')
			{
				tokens = splitLine(token, 0);
				if (tokens != NULL)
				{
					ret = execute_command(tokens, token);
					freeTokens(tokens);
				}
			}
			j = 0;
			j = 0;
		}
		token[j] = line[i];
		i++, j++;
		if ((line[i] == '\0'))
		{
			token[j] = '\0';
			if (token[0] != '\0')
			{
				tokens = splitLine(token, 0);
				if (tokens != NULL)
				{
					ret = execute_command(tokens, token);
					freeTokens(tokens);
				}
			}
		}
	}
	return (ret);
}
