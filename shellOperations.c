#include "shell.h"

/**
 * runShell - contains while loop for all shell operations
 */

void runShell(void)
{
	char *line = NULL, **tokens = NULL;
	size_t lineSize = 0;

	while (1)
	{
		printf("$ ");

		if (getline(&line, &lineSize, stdin) == -1)
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
		tokens = splitLine(line);
		execute_command(tokens);
	}
	free(line);
	freeTokens(tokens);
}
