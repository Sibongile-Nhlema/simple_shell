#include "shell.h"


/**
 * main - Acts as a command line interpreter
 *
 * @argc: Argument count
 * @argv: An array of command line arguments
 *
 * Return: 0
 */
int main(int argc __attribute__((unused)), char **argv)
{
	char *line = NULL, *lineCopy = NULL, **tokens = NULL;
	int status = 0;
	size_t lineSize = 0;

	while (1)
	{
		if (isatty(STDIN_FILENO))
			write(STDOUT_FILENO, "$ ", 2);
		if (getline(&line, &lineSize, stdin) == -1) /*Read a line from stdin*/
		{
			if (feof(stdin))
				break;
			perror("getline"), exit(EXIT_FAILURE);
		} lineCopy = myCustomStrdup(line);
		if (checkEmptyInput(lineCopy))
		{
			free(lineCopy);
			continue;
		}
		remove_comments_from_line(line);
		if (line[0] == '\0')
		{
			free(lineCopy);
			continue;
		}
		free(lineCopy);
		freeTokens(tokens); /*Free previous allocation*/
		if (myCustomStrstr(line, ";"))
		{
			status = splitSeparator(line);
			if (status)
				free(line), exit(status);
			continue;
		}
		if (myCustomStrstr(line, "||") || myCustomStrstr(line, "&&"))
		{
			status = splitLogicalLine(line);
			if (status)
				free(line), exit(status);
			continue;
		} tokens = splitLine(line, status); /*Split the line into tokens*/
		if (strcmp(tokens[0], "cd") == 0)
		{
			implementCdCommand(tokens, argv);
			continue;
		}
		if (strcmp(tokens[0], "env") == 0)
		{
			printEnvironment();
			continue;
		}
		if (myCustomStrcmp(tokens[0], "setenv") == 0)
		{
			if (tokens[1] != NULL)
				myCustomSetenv(tokens[1], tokens[2], 1);
			continue;
		}
		if (myCustomStrcmp(tokens[0], "unsetenv") == 0)
		{
			if (tokens[1] != NULL)
				myCustomUnsetenv(tokens[1]);
			continue;
		}
		if (myCustomStrcmp(tokens[0], "exit") == 0) /*Implement exit built-in*/
		{
			if (tokens[1] != NULL && (myCustomAtoi(tokens[1]) > 0 ||
						myCustomAtoi(tokens[1]) < 0 || myCustomAtoi(tokens[1]) == 0))
				status = findExitStatus(tokens, line, argv), exit(status);
			break;
		}
		if (tokens == NULL)
		{
			free(line);
			continue;
		} status = execute_command(tokens, line);
		if (status)
			free(line), freeTokens(tokens), exit(status);
	} free(line), freeTokens(tokens);
	return (0);
}
