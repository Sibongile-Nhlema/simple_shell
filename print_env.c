#include "shell.h"

/* all other environment files should ideally be coded in this file */

/**
 * print_env - prints the currents environment
 */

void print_env(void)
{
	extern char **environ;
	int i;

	for (i = 0; environ[i] != NULL; i++)
	{
		printf("%s\n", environ[i]);
	}
}
