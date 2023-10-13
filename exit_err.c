#include "shell.h"

/**
 * negativeExitError - Prints an error message when exit is called
 * with a negative status
 *
 * @exe: A pointer to the name of the executable
 * @status: A pointer to the status code
 */
void negativeExitError(char *exe, char *status)
{
	char errorMessage[100];
	char *errMsgMiddle = ": 1: exit: Illegal number: ";
	int length;

	length = 0;
	while (*exe)
		errorMessage[length++] = *exe++;

	while (*errMsgMiddle)
		errorMessage[length++] = *errMsgMiddle++;

	while (*status)
		errorMessage[length++] = *status++;

	errorMessage[length++] = '\n';
	errorMessage[length] = '\0';

	write(STDERR_FILENO, errorMessage, length);
}
/**
 * stringExitError - Prints an error message when exit is called
 * with a string as an argument
 *
 * @exe: A pointer to the name of the executable
 * @string: A pointer to the string argument
 */
void stringExitError(char *exe, char *string)
{
	char errorMessage[100];
	char *errMsgMiddle = ": 1: exit: Illegal number: ";
	int length;

	length = 0;
	while (*exe)
		errorMessage[length++] = *exe++;

	while (*errMsgMiddle)
		errorMessage[length++] = *errMsgMiddle++;

	while (*string)
		errorMessage[length++] = *string++;

	errorMessage[length++] = '\n';
	errorMessage[length] = '\0';

	write(STDERR_FILENO, errorMessage, length);
}
/**
 * printCdError - Prints an error if /root is cd's argument
 *
 * @exe: A pointer to the name of the executable
 * @dir: A pointer to the directory/path string
 */
void printCdError(char *exe, char *dir)
{
	char errorMessage[100];
	char *errMsgMiddle = ": 1: cd: can't cd to ";
	int length;

	length = 0;
	while (*exe)
		errorMessage[length++] = *exe++;

	while (*errMsgMiddle)
		errorMessage[length++] = *errMsgMiddle++;

	while (*dir)
		errorMessage[length++] = *dir++;

	errorMessage[length++] = '\n';
	errorMessage[length] = '\0';

	write(STDERR_FILENO, errorMessage, length);

}
