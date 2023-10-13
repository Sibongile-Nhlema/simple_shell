#include "shell.h"

int search_for_command(char **tokens, char *line);
char *search_in_dir(char **tokens, char *line);
char *exe_in_dir(char **tokens, char *line);
char *remove_quotes(char *command);
/**
 * execute_command - executes command line agruments and handles path
 * @tokens: command and arguments
 * @line: line read
 * Return: 0 on success, else returns commandPath
 */

int execute_command(char **tokens, char *line)
{
	int line_number = 0;
	int status, childExitStatus;
	char *commandPath;

	pid_t pid;

	if (tokens[0][0] == '\"' && tokens[0][myCustomStrlen(tokens[0]) - 1] == '\"')
	{
		tokens[0] = remove_quotes(tokens[0]);
	}
	if (search_for_command(tokens, line) == 0)
	{
		pid = fork();

		if ((pid) == -1)
		{
			perror("Error: Failed to fork the current process.\n");
			free(line);
			freeTokens(tokens);
			exit(EXIT_FAILURE);
		}
		if (pid == 0)
		{
			if ((execve(tokens[0], tokens, NULL) == -1))
			{
				if (myCustomStrchr(tokens[0], '/') != NULL)
				{
					free(line);
					freeTokens(tokens);
					exit(127);
				}
				commandPath = exe_in_dir(tokens, line);
				free(commandPath);
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

		line_number++;
		errMessage(tokens, line_number);
		free(line);
		freeTokens(tokens);
		exit(127);
	}
	return (0);
}

/**
 * search_for_command - finds command in current directory
 * @tokens: command and arguments
 * @line: line read
 * Return: 1 on error, 0 on success
 */

int search_for_command(char **tokens, char *line)
{
	char *commandPath;

	if (myCustomStrchr(tokens[0], '/') != NULL) /* Check if cmd has path*/
	{
		return (0);
	}
	else
	{
		commandPath = search_in_dir(tokens, line);
		if (commandPath != NULL)
		{
			free(commandPath);
			return (0);
		}
		else
		{
			free(commandPath);
			return (1);
		}
	}
	return (0);
}

/**
 * search_in_dir - searches in directories for full path
 * @tokens: command and arguments entered by user
 * @line: line read
 * Return: Null if not found, commandPath if found in dir
 */

char *search_in_dir(char **tokens, char *line)
{
	char *path, *commandPath, *pathCopy, *token = NULL;
	int line_number = 0;

	path = myCustomGetenv("PATH");
	pathCopy = myCustomStrdup(path);

	if (pathCopy == NULL)
	{
		line_number++;
		errMessage(tokens, line_number);
		free(line);
		freeTokens(tokens);
		exit(127);
	}

	token = strtok(pathCopy, ":");

	while (token != NULL)
	{
		commandPath = malloc(myCustomStrlen(token)
				+ myCustomStrlen(tokens[0]) + 2);
		if (commandPath == NULL)
		{
			line_number++;
			errMessage(tokens, line_number);
			free(pathCopy);
			free(line);
			freeTokens(tokens);
			exit(127);
		}
		myCustomStrcpy(commandPath, token);
		myCustomStrcat(commandPath, "/"); /* Append a slash to directory path */
		myCustomStrcat(commandPath, tokens[0]); /* Append command name to dir path */
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
 * @line: line read
 * Return: Null on success, nothing on error
 */

char *exe_in_dir(char **tokens, char *line)
{
	char *path, *commandPath, *pathCopy, *token = NULL;
	int line_number = 0;

	path = myCustomGetenv("PATH");
	pathCopy = myCustomStrdup(path);

	if (pathCopy == NULL)
	{
		perror("Error: Failed to allocate memory for pathCopy.\n");
		free(line);
		freeTokens(tokens);
		exit(127);
	}
	token = strtok(pathCopy, ":");
	while (token != NULL)
	{
		commandPath = malloc(myCustomStrlen(token)
				+ myCustomStrlen(tokens[0]) + 2);

		if (commandPath == NULL)
		{
			perror("Error: Failed to allocate memory for commandPath.\n");
			free(pathCopy);
			free(line);
			freeTokens(tokens);
			exit(127);
		}
		myCustomStrcpy(commandPath, token);
		myCustomStrcat(commandPath, "/");
		myCustomStrcat(commandPath, tokens[0]);

		if (access(commandPath, X_OK) == 0)
		{
			if ((execve(commandPath, tokens, environ) == -1))
			{
				line_number++;
				errMessage(tokens, line_number);
				free(commandPath);
				free(pathCopy);
				free(line);
				freeTokens(tokens);
				exit(127);
			}
		}
		free(commandPath);
		token = strtok(NULL, ":");
	}
	free(pathCopy);
	return (NULL);
}

/**
 * remove_quotes - removes quotes so that a command can be executed
 * @command: command
 *
 * Return: command without quotes
 */

char *remove_quotes(char *command)
{
	int i, j;
	int len = myCustomStrlen(command);

	for (i = 0, j = 0; i < len; i++)
	{
		if (command[i] != '\"')
			command[j++] = command[i];
	}
	command[j] = '\0';

	return (command);
}
