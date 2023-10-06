#include "shell.h"

/**
 * main - Acts as a command line interpreter
 *
 * Return: 0
 */
int main (void)
{
	char *command = NULL, *commandCopy, **tokens = NULL, *token = NULL;
	size_t n = 0;
	int i;

	while (1)
	{
		printf("$ ");

		if (getline(&command, &n, stdin) == -1) /*Get the command line*/
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
		commandCopy = strdup(command);
		token = strtok(command, DELIM); /*Count the tokens*/
		i = 0;
		while (token != NULL)
		{
			i++;
			token = strtok(NULL, DELIM);
		}
		tokens = malloc(i * sizeof(char *));
		if (tokens == NULL)
		{
			exit(EXIT_FAILURE);
		}
		i = 0;
		token = strtok(commandCopy, DELIM); /*Add tokens to the tokens array*/
		while (token != NULL)
		{
			tokens[i] = token;
			i++;
			token = strtok(NULL, DELIM);
		}
		tokens[i] = NULL;
		/*handles execution */
		execute_command(tokens);
	}
	free(command);
	free(commandCopy);
	free(tokens);
	return (0);
}
