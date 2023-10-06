#include "shell.h"

/**
 * main - Acts as a command line interpreter
 *
 * Return: 0
 */
int main (void)
{
	char *line = NULL, **tokens = NULL;
	size_t lineSize = 0;

	while (1)
	{
		printf("$ ");

		if (getline(&line, &lineSize, stdin) == -1) /*Get the command line*/
		{
			if (feof(stdin))
			{
				break;
			}
			else
			{
				perror("Error: Failed to read command line.\n");
				exit(EXIT_FAILURE); /*Should we exit??*/
			}
		}
		tokens = splitLine(line); /*Split the line into tokens*/
		/*handles execution */
		execute_command(tokens);
	}
	free(line);
	freeTokens(tokens);
	return (0);
}
