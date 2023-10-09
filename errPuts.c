#include "shell.h"

/**
 * errPuts - prints an input string
 * @string: string
 */

void errPuts(char *string)
{
	int i = 0;

	if (!string)
		return;
	while (string[i] != '\0')
	{
		errPutchar(string[i]);
		i++;
	}
}

/**
 * errPutchar - writes a character to stderr
 * @c: character
 *
 * Return: 1 if succesful, otherwise -1 (error)
 */

int errPutchar(char c)
{
	static int n;
	static char buffer[1024];

	if (c == -1 || n >= 1024)
	{
		write(2, buffer, n);
		n = 0;
	}
	if (c != -1)
	{
		buffer[n++] = c;
	}
	return (1);
}

/**
 * errMessage - prints error message
 * @info: the parameter & return info struct
 * @estr: string containing specified error type
 * Return: 0 if no numbers in string, converted number otherwise
 */

void errMessage(char **tokens, int line_number)
{

	errPuts("./hsh");
	errPuts(": ");
	printDecimal(line_number, STDERR_FILENO);
	errPuts(": ");
	errPuts(tokens[0]);
	errPuts(": ");
	errPuts("not found\n");
	errPutchar(-1);
}

/**
 * printDecimal - prints decimal number of base 10
 * @input
 * @fd: file descriptor
 *
 * Return: number of chars printed
 */

int printDecimal(int input, int fd)
{
	int (*shell_putchar)(char) = ourPutChar;
	int i, counter = 0;
	unsigned int abso, curr;

	if (fd == STDERR_FILENO)
		shell_putchar = errPutchar;
	if (input < 0)
	{
		abso = -input;
		shell_putchar('-');
		counter++;
	}
	else
		abso = input;
	curr = abso;
	for (i = 1000000000; i > 1; i /= 10)
	{
		if (abso/ i)
		{
			 shell_putchar('0' + curr / i);
			 counter++;
		}
		curr %= i;
	}
	shell_putchar('0' + curr);
	counter++;

	return (counter);
}
