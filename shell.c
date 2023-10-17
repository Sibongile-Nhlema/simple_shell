#include "shell.h"

#define SEMICOLON_OR_AND (myCustomStrstr(line, ";") || \
	myCustomStrstr(line, "||") || myCustomStrstr(line, "&&"))

#define CD_ENV_SETENV_UNSETENV_EXIT (strcmp(tokens[0], "cd") == 0 || \
		strcmp(tokens[0], "env") == 0 || \
		myCustomStrcmp(tokens[0], "setenv") == 0 || \
		myCustomStrcmp(tokens[0], "unsetenv") == 0 || \
		myCustomStrcmp(tokens[0], "exit") == 0)

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
	int status = 0, status2 = 0;
	size_t lineSize = 0;

	while (1)
	{
		printPrompt();
		if (getline(&line, &lineSize, stdin) == -1) /*Read a line from stdin*/
		{
			if (feof(stdin))
				break;
			perror("getline"), exit(EXIT_FAILURE); }
		if (emptyHandler(line))
			continue;
		remove_comments_from_line(line);
		if (line[0] == '\0')
			continue;
		free(lineCopy), freeTokens(tokens); /*Free previous allocation*/
		if (SEMICOLON_OR_AND) /*Implement ;, || and &&*/
		{
			checkLine(line, &status2);
			if (status2)
				free(line), exit(status2);
			continue; }
		tokens = splitLine(line, status); /*Split the line into tokens*/
		if (CD_ENV_SETENV_UNSETENV_EXIT) /*Implement cd, env, setenv, exit*/
		{
			checkTokens(tokens, argv, line, &status2);
			if (myCustomStrcmp(tokens[0], "exit") == 0)
			{
				if (status2)
					freeTokens(tokens), exit(status2);
				break; }
			continue; }
		status = execute_command(tokens, line);
		if (status)
			free(line), freeTokens(tokens), exit(status);
	} free(line), freeTokens(tokens);
	return (0);
}

/**
 * printPrompt - Prints a prompt
 */
void printPrompt(void)
{
	if (isatty(STDIN_FILENO))
		write(STDOUT_FILENO, "$ ", 2);
}
/**
 * emptyHandler - Calls checkEmptyInput function
 *
 * @line: A pointer to the command line
 *
 * Return: 1 if input is empty, 0 if not
 */
int emptyHandler(char *line)
{
	char *lineCopy;
	int ret = 0;

	lineCopy = myCustomStrdup(line);

	ret = checkEmptyInput(lineCopy);
	free(lineCopy);

	return (ret);
}
