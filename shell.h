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
#define UNUSED(x) (void)(x)

extern char **environ;

/* execute_command.c functions*/
int execute_command(char **tokens, char *line);
int search_for_command(char **tokens, char *line);
char *search_in_dir(char **tokens, char *line);
char *exe_in_dir(char **tokens, char *line);

/*cd command Implementation*/
void implementCdCommand(char **tokens, char **argv);
void setOldPwd(void);
void cdNoArgument(void);
void handleCdDash(void);
void printCdError(char *exe, char *dir);

/*exit command Implementation*/
char **implementExit(char *token, char *lineCopy);
void negativeExitError(char *exe, char *status);
void stringExitError(char *exe, char *string);
char **positiveStatusHandler(char *status, char *lineCopy, char *token);
char **negativeStatusHandler(char *status, char *lineCopy, char *token);
char **stringStatusHandler(char *status, char *lineCopy, char *token);
int findExitStatus(char **tokens, char *line, char **argv);

/*Logical Operators Implementation*/
int splitLogicalLine(char *line);


/*Variable Substitution*/
char *handleSubstitution(char *token, int status);
void reverseString(char *string);
void intToStr(char *string, int number, int index);

/* remove comments implementaion*/
void remove_comments_from_line(char *string);

/* Environment changes*/
int myCustomUnsetenv(const char *name);

/* error message handling errPuts.c */
void errMessage(char **tokens, int line_number);
int errPutchar(char c);
void errPuts(char *string);
int printDecimal(int input, int fd);
int ourPutChar(char c);

/*Other functions*/
char **splitLine(char *line, int status);
void freeTokens(char **tokens);
void search_and_execute_command(char **tokens);
void printEnvironment(void);
int checkEmptyInput(char *line);

/*Custom Functions*/
int myCustomStrcmp(char *str1, char *str2);
int myCustomStrlen(char *string);
char *myCustomStrdup(char *string);
char *myCustomStrchr(char *string, char character);
char *myCustomStrcpy(char *destination, char *source);
char *myCustomStrcat(char *destination, char *source);
int myCustomStrncmp(const char *string1, const char *string2, int n);
char *myCustomStrstr(char *string, char *substring);
int myCustomAtoi(char *string);
int myCustomIsSpace(int character);
char *myCustomGetenv(char *varName);
int myCustomSetenv(const char *name, const char *value, int overwrite);
ssize_t myCustomGetline(char **lineptr, size_t *n);

/* custom constant string functions*/
int const_strncmp(char *string1, const char *string2, size_t number);
int const_strlen(const char *string);

#endif
