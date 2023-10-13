#include "shell.h"

/**
 * printEnvironment - Implements the env built-in command
 */
void printEnvironment(void)
{
	char **environment;

	environment = environ;

	while (*environment)
	{
		write(STDOUT_FILENO, *environment, myCustomStrlen(*environment));
		write(STDOUT_FILENO, "\n", 1);
		environment++;
	}

}
