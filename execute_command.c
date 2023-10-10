#include "shell.h"

int search_for_command(char **tokens);
char *search_in_dir(char **tokens);
char *exe_in_dir(char **tokens);
void myCustomPrint(char *message);

/**
 * myCustomPrint - prints a string to stdout
 * @message: string
 */

void myCustomPrint(char *message)
{
	write(1, message, myCustomStrlen(message));
}

/**
 * execute_command - executes command line agruments and handles path
 * @tokens: command and arguments
 *
 * Return: 0 on success, 2 on failure
 */

int execute_command(char **tokens)
{
	pid_t pid;
	int status, childExitStatus;

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
		}
		else
		{
			wait(&status);
			if (WIFEXITED(status))
			{
				childExitStatus = WEXITSTATUS(status);
				return (childExitStatus);
			}
		}
	}
	else
	{
		myCustomPrint(tokens[0]);
		myCustomPrint(": command not found\n");
	}
	return (0);
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
		myCustomStrcat(commandPath, "/"); /* Append a slash to directory path */
		myCustomStrcat(commandPath, tokens[0]); /* Append command name to dir path */

		if (commandPath == NULL)
		{
			perror("Error: Failed to allocate memory for commandPath.\n");
			free(pathCopy);
			exit(EXIT_FAILURE);
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
