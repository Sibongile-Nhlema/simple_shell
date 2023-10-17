#include "shell.h"

/**
 * myCustomUnsetenv - deletes an environment variable
 * @name: name of variable
 *
 * Return: Always 0
 */

int myCustomUnsetenv(const char *name)
{
	int j;
	int i = 0, found = 0;

	while (environ[i] != NULL)
	{
		if (const_strncmp(environ[i], name, const_strlen(name)) ==
				0 && environ[i][const_strlen(name)] == '=')
		{
			found = 1;
			break;
		}
		i++;
	}

	if (found)
	{
		for (j = i; environ[j + 1] != NULL; j++)
		{
			environ[j] = environ[j + 1];
		}
	}
	return (found ? 0 : -1);
}
