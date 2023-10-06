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
	pid_t pid;

	while (1)
	{
		printf("$ ");

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

		tokens = splitLine(line); /*Split the line into tokens*/
		if (tokens == NULL)
			exit(EXIT_FAILURE);

		if ((pid = fork()) == -1)
		{
			perror("Error: Failed to fork the current process.\n");
			exit(EXIT_FAILURE);
		}
		if (pid == 0) /*Execute the command in the child process*/
		{
			if (execve(tokens[0], tokens, NULL) == -1)
			{
				perror("Error: No such file or directory.\n");
			}
		}
		else
		{
			wait(NULL);
		}
	}
	free(line);
	freeTokens(tokens);
	return (0);
}
