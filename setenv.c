#include "shell.h"

/**
 * myCsutomSetenv - change or adds an environment variable
 * @name: name of variable
 * @value: the value to use
 * @overwrite: an interger
 *
 * Return: 0 on success, -1 on error
 */

int myCustomSetenv(const char *name, const char *value, int overwrite)
{
	char **new_environ = NULL, **old_environ = NULL, *new_var = NULL;
	size_t len;
	int index, environ_size = 0;
	(void)overwrite;

	/*find length of new env var*/
	if (name == NULL || value == NULL)
		return (-1); /*avoid segmentation fault*/

	len = const_strlen(name) + const_strlen(value) + 2;
	new_var = (char *)malloc(len);/*memory for new env var*/
	if (new_var == NULL)
		return (-1);
	const_strcpy(new_var, name);
	const_strcat(new_var, "=");
	const_strcat(new_var, value);

	while (environ[environ_size] != NULL)
		environ_size++;

	old_environ = (char **)malloc((environ_size + 1) * sizeof(char *));
	memcpy(old_environ, environ, (environ_size + 1) * sizeof(char *));

	index = 0; /*find position of env var in environ array*/
	while (old_environ[index] != NULL)
	{
		if (const_strncmp(old_environ[index], name, const_strlen(name)) == 0)
		{
			old_environ[index] = new_var;
			environ = old_environ;
			return (0);
		}
		else
		{
			free(new_var);
			free(old_environ);
			return (0);
		}
		index++;
	}
	new_environ = (char **)realloc(old_environ,(index + 2) * sizeof(char *));
	if (new_environ == NULL)
	{
		free(old_environ);
		free(new_var);
		return (-1);
	}
	old_environ = new_environ;
	free(old_environ);
	new_environ[index] = new_var;
	new_environ[index + 1] = NULL;
	environ = new_environ;
	return (0);
}
