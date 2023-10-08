#include "shell.h"

/**
 * main - Acts as a command line interpreter
 *
 * Return: 0
 */
int main(void)
{
	char *line = NULL, **tokens = NULL, *prompt = "$ ";
	size_t lineSize = 0;

	while (1)
	{
		write(STDOUT_FILENO, prompt, 2);

		if (getline(&line, &lineSize, stdin) == -1) /*Read a line from stdin*/
		{
			if (feof(stdin))
			{
				break;
			}
			else
			{
				perror("Error: Failed to read command line.\n");
				exit(EXIT_FAILURE);
			}
		}
		freeTokens(tokens); /*Free previous allocation*/
		tokens = splitLine(line); /*Split the line into tokens*/
		if (myCustomStrcmp(tokens[0], "exit") == 0) /*Implement exit built-in*/
		{
			if (tokens[1] != NULL && myCustomAtoi(tokens[1]))
			{
				exit(myCustomAtoi(tokens[1]));
			}
			break;
		}
		if (tokens == NULL)
		{
			free(line);
			continue;
		}
		/*handles execution */
		execute_command(tokens);
	}
	free(line);
	freeTokens(tokens);
	return (0);
}
