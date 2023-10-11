#include "shell.h"

/**
 * main - Acts as a command line interpreter
 *
 * @argc: Argument count
 * @argv: An array of command line arguments
 *
 * Return: 0
 */
int main(int argc, char **argv)
{
	char *line = NULL, *lineCopy = NULL, **tokens = NULL;
	int status;
	size_t lineSize = 0;

	UNUSED(argc);
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
			if (tokens[1] != NULL && (myCustomAtoi(tokens[1]) > 0 ||
						myCustomAtoi(tokens[1]) < 0 || myCustomAtoi(tokens[1]) == 0))
			{
				status = findExitStatus(tokens, line, argv);
				exit(status);
			}
			break;
		}
		if (tokens == NULL)
		{
			free(line);
			continue;
		}
		status = execute_command(tokens, line);
		if (status)
			free(line), freeTokens(tokens), exit(status);
	}
	free(line), freeTokens(tokens);
	return (0);
}
