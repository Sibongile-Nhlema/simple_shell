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

void execute_command(char **tokens);

#endif
