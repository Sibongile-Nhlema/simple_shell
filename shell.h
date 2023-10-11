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

#define DELIM " \n\t\r\a"
#define UNUSED(x) (void)(x)

extern char **environ;

/* execute_command.c functions*/
int execute_command(char **tokens, char *line);
int search_for_command(char **tokens, char *line);
char *search_in_dir(char **tokens, char *line);
char *exe_in_dir(char **tokens, char *line);

/* error message handling errPuts.c */
void errMessage(char **tokens, int line_number);
int errPutchar(char c);
void errPuts(char *string);
int printDecimal(int input, int fd);
int ourPutChar(char c);

char **splitLine(char *line);
void freeTokens(char **tokens);
void search_and_execute_command(char **tokens);
char **implementExit(char *token, char *lineCopy);
int myCustomStrcmp(char *str1, char *str2);
int myCustomStrlen(char *string);
char *myCustomStrdup(char *string);
char *myCustomStrchr(char *string, char character);
char *myCustomGetenv(char *varName);
char *myCustomStrcpy(char *destination, char *source);
char *myCustomStrcat(char *destination, char *source);
int myCustomAtoi(char *string);
int myCustomIsSpace(int character);
int checkEmptyInput(char *line);
void negativeExitError(char *exe, char *status);
void stringExitError(char *exe, char *string);
char **positiveStatusHandler(char *status, char *lineCopy, char *token);
char **negativeStatusHandler(char *status, char *lineCopy, char *token);
char **stringStatusHandler(char *status, char *lineCopy, char *token);
int findExitStatus(char **tokens, char *line, char **argv);

#endif
