/**
 * sea_print -  (printf substitute). prints strings to console
 * @*input: string to be printed
 */

void sea_print(const char *input)
{
	return (write(STDOUT_FILENO, input, custom_strlen(input)));
}
