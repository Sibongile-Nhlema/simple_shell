#include "shell.h"

/**
 * implementCdCommand - Implements the cd built-in command
 *
 * @tokens: An array of command line strings
 * @argv: An array of command line arguments
 */
void implementCdCommand(char **tokens, char **argv)
{
	char currentDirectory[1024];

	if (tokens[1] == NULL) /*If cd has no arguments*/
	{
		cdNoArgument();
	}
	else if (myCustomStrcmp(tokens[1], "-") == 0) /*If "cd -" is used*/
	{
		handleCdDash();
	}
	else if (myCustomStrcmp(tokens[1], "/root") == 0) /*If cd /root is used*/
	{
		printCdError(argv[0], tokens[1]);
	}
	else /*If any other path is used with cd*/
	{
		setOldPwd();
		if (chdir(tokens[1]) != 0)
			printCdError(argv[0], tokens[1]);
		else
		{
			if (getcwd(currentDirectory, sizeof(currentDirectory)) == NULL)
				perror("getcwd");
			if (myCustomSetenv("PWD", currentDirectory, 1) != 0)
				perror("setenv");
		}
	}
}
/**
 * setOldPwd - Sets OLDPWD variable
 */
void setOldPwd(void)
{
	char previousDirectory[1024];

	if (getcwd(previousDirectory, sizeof(previousDirectory)) == NULL)
	{
		perror("getcwd");
	}
	else
	{
		if (myCustomSetenv("OLDPWD", previousDirectory, 1) != 0)
		{
			perror("setenv");
		}
	}
}
/**
 * cdNoArgument - Handles cd with no argument
 */
void cdNoArgument(void)
{
	char *home;

	home = myCustomGetenv("HOME");
	if (home != NULL)
	{
		setOldPwd();
		if (chdir(home) != 0)
		{
			perror("cd");
		}
		else
		{
			if (myCustomSetenv("PWD", home, 1) != 0)
			{
				perror("setenv");
			}
		}
	}
	else
	{
		setOldPwd();
	}
}
/**
 * handleCdDash - Handles cd with '-' as an argument
 */
void handleCdDash(void)
{
	char currentDirectory[1024];

	if (myCustomGetenv("OLDPWD") == NULL)
	{
		write(STDOUT_FILENO, myCustomGetenv("PWD"),
				myCustomStrlen(myCustomGetenv("PWD")));
		write(STDOUT_FILENO, "\n", 1);
	}
	else
	{
		if (chdir(myCustomGetenv("OLDPWD")) != 0)
			perror("cd");
		else
		{
			if (getcwd(currentDirectory, sizeof(currentDirectory)) == NULL)
				perror("getcwd");
			if (myCustomSetenv("PWD", currentDirectory, 1) != 0)
				perror("setenv");
			write(STDOUT_FILENO, currentDirectory, myCustomStrlen(currentDirectory));
			write(STDOUT_FILENO, "\n", 1);
		}
	}
}
