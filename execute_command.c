#include "shell.h"

/**
 * execute_command - executes command line agruments
 * @token: command
 */

void execute_command(char **tokens)
{
	char *commandPath;
	char *path;
	char *pathCopy;
	char *token = NULL;

	struct stat st; /* predefined struct in sys.stat (provides info about a file) */

	pid_t pid;

	if ((pid = fork()) == -1)
	{
		perror("Error: Failed to fork the current process.\n");
		exit(EXIT_FAILURE);
	}
	if (pid == 0)
	{
		if (strchr(tokens[0], '/') != NULL) /* Check if the command contains a path */
		{
			if ((pid = fork()) == -1)
			{
				perror("Error: Failed to fork the current process.\n");
			}
			if (pid == 0) /* Execute the command in the child process */
			{
				if (strcmp(tokens[0], "exit") == 0)
				{
					exit(0);
				}
				if (execve(tokens[0], tokens, NULL) == -1)
				{
					perror("Error: No such file or directory.\n");
					exit(EXIT_FAILURE);
				}
			}
			else
			{
				wait(NULL);
			}
		}
		else /* Search for the command in the directories specified by the PATH environment variable */
		{
			path = getenv("PATH");
			pathCopy = strdup(path);
			token = strtok(pathCopy, ":");

			while (token != NULL)
			{
				commandPath = malloc(strlen(token) + strlen(tokens[0]) + 2);
				strcpy(commandPath, token);
				strcat(commandPath, "/");
				strcat(commandPath, tokens[0]);

				if (stat(commandPath, &st) == 0 && st.st_mode & S_IXUSR) /* Check if the command exists and is executable */
				{
					if ((pid = fork()) == -1)
					{
						perror("Error: Failed to fork the current process.\n");
						return;
					}
					if (pid == 0) /* Execute the command in the child process */
					{
						if (execve(commandPath, tokens, NULL) == -1)
						{
							perror("Error: Failed to execute the command.\n");
							exit(EXIT_FAILURE);
						}
					}
					else
					{
						wait(NULL);
						return;
					}
				}
				free(commandPath);
				token = strtok(NULL, ":");
			}
			free(pathCopy);
		}
	}
	else
	{
		wait(NULL);
	}
}
