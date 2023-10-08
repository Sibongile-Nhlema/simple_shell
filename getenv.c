#include "shell.h"

/**
 * myCustomGetenv - Searches the environment list to find the var name
 *
 * @varName: A pointer to the name to find
 *
 * Return: A pointer to the value in the environment, or NULL if no match.
 */
char *myCustomGetenv(char *varName)
{
	int i, j, flag;
	char *varValue;

	i = 0;
	while (environ[i])
	{
		flag = 1;
		j = 0;
		while (environ[i][j] != '=') /*Check if what's before '=' equals varName*/
		{
			if (environ[i][j] != varName[j])
			{
				flag = 0;
				break;
			}
			j++;
		}
		if (flag)
		{
			varValue = &environ[i][j + 1]; /*Skip over the '=' sign*/
			return (varValue);
		}
		i++;
	}

	return (NULL);
}
