#ifndef SHELL_H
#define SHELL_H
/* general purpose */
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
/* string manipulation */
#include <string.h>
/*file operations */
#include <fcntl.h>
/*system call librabries */
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
/* limitations (INT_MAX/INT_MIN) */
#include <limits.h>
/* error handling */
#include <errno.h>

#define DELIM " \n\t"

extern char **environ;

void execute_command(char **tokens);
char **splitLine(char *line);
void freeTokens(char **tokens);
void search_and_execute_command(char **tokens);
int myCustomStrcmp(char *str1, char *str2);
int myCustomStrlen(char *string);
char *myCustomStrdup(char *string);
char *myCustomStrchr(char *string, char character);
char *myCustomGetenv(char *varName);
char *myCustomStrcpy(char *destination, char *source);
char *myCustomStrcat(char *destination, char *source);

#endif
