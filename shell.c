#include "shell.h"

/**
 * main - Acts as a command line interpreter
 *
 * Return: 0
 */
int main(void)
{
	char *line = NULL, *lineCopy = NULL, **tokens = NULL;
	int status;
	size_t lineSize = 0;

	while (1)
	{
		if (isatty(STDIN_FILENO))
			write(STDOUT_FILENO, "$ ", 2);
		if (getline(&line, &lineSize, stdin) == -1) /*Read a line from stdin*/
		{
			if (feof(stdin))
				break;
			perror("Error: Failed to read command line.\n");
			exit(EXIT_FAILURE);
		}
		lineCopy = myCustomStrdup(line);
		if (checkEmptyInput(lineCopy))
		{
			free(lineCopy);
			continue;
		}
		free(lineCopy);
		freeTokens(tokens); /*Free previous allocation*/
		tokens = splitLine(line); /*Split the line into tokens*/
		if (myCustomStrcmp(tokens[0], "exit") == 0) /*Implement exit built-in*/
		{
			if (tokens[1] != NULL && myCustomAtoi(tokens[1]))
			{
				status = myCustomAtoi(tokens[1]);
				free(line);
				freeTokens(tokens);
				exit(status);
			}
			break;
		}
		if (tokens == NULL)
		{
			free(line);
			continue;
		}
		execute_command(tokens);
	}
	free(line);
	freeTokens(tokens);
	return (0);
}
