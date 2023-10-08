#include "shell.h"

void search_and_execute_command(char **tokens);

/**
 * execute_command - executes command line agruments and handles path
 * @tokens: command and arguments
 */

void execute_command(char **tokens)
{
	pid_t pid;

	pid = fork();

	if ((pid) == -1)
	{
		perror("Error: Failed to fork the current process.\n");
		exit(EXIT_FAILURE);
	}
	if (pid == 0)
	{
		search_and_execute_command(tokens);
	}
	else
	{
		wait(NULL);
	}
}

/**
 * search_and_execute_command - finds command or path and executes accordingly
 * @tokens: command and arguments
 */

void search_and_execute_command(char **tokens)
{
	char *path, *commandPath, *pathCopy, *token = NULL;

	/* Check if command contains a path*/
	if (myCustomStrchr(tokens[0], '/') != NULL)
	{
		if (execve(tokens[0], tokens, NULL) == -1)
		{
			perror("Error: No such file or directory.\n");
			exit(EXIT_FAILURE);
		}
	}
	else /* Search for command in directories specified by PATH env var */
	{
		path = myCustomGetenv("PATH");
		pathCopy = myCustomStrdup(path);
		token = strtok(pathCopy, ":"); /* Split PATH str into individual dir */

		if (pathCopy == NULL)
		{
			perror("Error: Failed to allocate memory for pathCopy.\n");
			exit(EXIT_FAILURE);
		}

		while (token != NULL)
		{
			commandPath = malloc(myCustomStrlen(token) + myCustomStrlen(tokens[0]) + 2);
			myCustomStrcpy(commandPath, token);
			myCustomStrcat(commandPath, "/"); /* Append a slash to directory path */
			/* Append command name to directory path */
			myCustomStrcat(commandPath, tokens[0]);

			if (commandPath == NULL)
			{
				perror("Error: Failed to allocate memory for commandPath.\n");
				exit(EXIT_FAILURE);
			}
			if (access(commandPath, X_OK) == 0)
			{
				if (execve(commandPath, tokens, environ) == -1) /* Execute the command */
				{
					perror("Error: Failed to execute the command.\n");
					exit(EXIT_FAILURE);
				}
				else
				{
					perror("Error: No such file or directory.\n");
					exit(EXIT_FAILURE);
				}
			}
			free(commandPath);
			token = strtok(NULL, ":"); /* Move to next directory in PATH */
		}
		free(pathCopy);
	}
	printf("Error: '%s' is not a valid command.\n", tokens[0]);
	exit(EXIT_FAILURE);
}
