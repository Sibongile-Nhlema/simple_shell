#include "shell.h"

int search_for_command(char **tokens);
char *search_in_dir(char **tokens);
char *exe_in_dir(char **tokens);

/**
 * execute_command - executes command line agruments and handles path
 * @tokens: command and arguments
 */

void execute_command(char **tokens)
{
	int line_number = 0;

	pid_t pid;

	if (search_for_command(tokens) == 0)
	{
		pid = fork();

		if ((pid) == -1)
		{
			perror("Error: Failed to fork the current process.\n");
			exit(EXIT_FAILURE);
		}
		if (pid == 0)
		{
			if ((execve(tokens[0], tokens, environ) == -1))
			{
				if (myCustomStrchr(tokens[0], '/') != NULL)
				{
					exit(2);
				}
				exe_in_dir(tokens);
			}
			{
				exit(127);
			}
		}
		else
		{
			wait(NULL);
		}
	}
	else
	{
		line_number++;
		errMessage(tokens, line_number);
	}
}

/**
 * search_for_command - finds command in current directory
 * @tokens: command and arguments
 *
 * Return: 1 on error, 0 on success
 */

int search_for_command(char **tokens)
{
	char *commandPath;
	if (myCustomStrchr(tokens[0], '/') != NULL) /* Check if cmd has path*/
	{
		return (0);
	}
	else
	{
		commandPath = search_in_dir(tokens);
		if (commandPath != NULL)
		{
			free(commandPath);
			return (0);
		}
		else
			return (1);
	}
	return (0);
}

/**
 * search_in_dir - searches in directories for full path
 * @tokens: command and arguments entered by user
 *
 * Return: Null if not found, commandPath if found in dir
 */

char *search_in_dir(char **tokens)
{
	char *path, *commandPath, *pathCopy, *token = NULL;
	int line_number = 0;

	path = myCustomGetenv("PATH");
	pathCopy = myCustomStrdup(path);
	token = strtok(pathCopy, ":");

	if (pathCopy == NULL)
	{
		line_number++;
		errMessage(tokens, line_number);
		exit(127);
	}
	while (token != NULL)
	{
		commandPath = malloc(myCustomStrlen(token)
				+ myCustomStrlen(tokens[0]) + 2);
		myCustomStrcpy(commandPath, token);
		myCustomStrcat(commandPath, "/"); /* Append a slash to directory path */
		myCustomStrcat(commandPath, tokens[0]); /* Append command name to dir path */

		if (commandPath == NULL)
		{
			line_number++;
			errMessage(tokens, line_number);
			free(pathCopy);
			exit(127);
		}
		if (access(commandPath, X_OK) == 0)
		{
			free(pathCopy);
			return (commandPath);
		}
		free(commandPath);
		token = strtok(NULL, ":"); /* Move to next directory in PATH */
	}
	free(pathCopy);
	return (NULL);
}

/**
 * exe_in_dir - executes command found in path
 * @tokens: command and argument
 *
 * Return: Null on success, nothing on error
 */

char *exe_in_dir(char **tokens)
{
	char *path, *commandPath, *pathCopy, *token = NULL;

	path = myCustomGetenv("PATH");
	pathCopy = myCustomStrdup(path);
	token = strtok(pathCopy, ":");

	if (pathCopy == NULL)
	{
		perror("Error: Failed to allocate memory for pathCopy.\n");
		exit(EXIT_FAILURE);
	}
	while (token != NULL)
	{
		commandPath = malloc(myCustomStrlen(token)
				+ myCustomStrlen(tokens[0]) + 2);
		myCustomStrcpy(commandPath, token);
		myCustomStrcat(commandPath, "/");
		myCustomStrcat(commandPath, tokens[0]);

		if (commandPath == NULL)
		{
			perror("Error: Failed to allocate memory for commandPath.\n");
			exit(EXIT_FAILURE);
		}
		if (access(commandPath, X_OK) == 0)
		{
			if ((execve(commandPath, tokens, environ) == -1))
			{
				perror("Error: No such file or directory.\n");
				exit(EXIT_FAILURE);
			}
		}
		free(commandPath);
		token = strtok(NULL, ":");
	}
	free(pathCopy);
	return (NULL);
}
