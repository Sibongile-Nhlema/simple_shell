#include "shell.h"

/**
 * myCustomIsSpace - Looks for whitespace
 *
 * @character: A character
 *
 * Return: 1 if the character is whitespace, 0 if it isn't
 */
int myCustomIsSpace(int character)
{
	return (character == ' ' || character == '\t'
			|| character == '\n' || character == '\r'
			|| character == '\v' || character == '\f');
}
