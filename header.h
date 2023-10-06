#ifndef HEADER_H
#define HEADER_H

#include <unistd.h>
#include <dirent.h>
#include <stdlib.h>
#include <stdio.h>
#include <signal.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <string.h>
#include <sys/wait.h>
/* The above libraries contain the allowed functions in the project */

/* printing to stdout */
int sea_putchar(char c);
int sea_printf(const char *input);

/*custom functions from <string.h> */
size_t sea_strlen(const char *str);
size_t sea_strcspn(const char *str1, const char *str2);

char *strcpy(char *dest, const char *src);
char *sea_strdup(const char *s);
char *sea_strcat(char *dest, const char *src);
char *sea_strncat(char *dest, const char *strc, size_t n);
char *sea_strchr(const char *str, int c);
char *sea_strtok(char *str, const char *delim);
char *sea_strstr(const char *haystack, const char *needle);

int *sea_strcmp(const char *str1, const char *str2);
int *sea_strncmp(const char *str1, const char *str2, size_t n);

/* memory allocation functions */
void *sea_realloc(void *ptr, size_t size);
void *sea_memset(void *str, int c, size_t n);

/* envirnment functions */
int sea_putenv(char *str);

#endif
