#ifndef SHELL_H
#define SHELL_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <limits.h>
#include <fcntl.h>
#include <errno.h>

#define DELIM " \t\n"
#define DEFAULT_LINE_SIZE 128
#define DIR_SIZE 1024
extern char **environ;

/**
 * struct command - defines new data type for a command
 * @path: command path
 * @found: it sets for 1 if command found, 0 in case of not found
 */
typedef struct command
{
	char *path;
	int found;
} CommandResult;

char *read_line(void);

char *_stdup(const char *str);
int _stcmp(char *a1, char *a2);
int _stlen(char *a);
char *_stcat(char *dest, char *src);
char *_stcpy(char *dest, char *src);
char **tokenizer(char *line);
char **tokenizer(char *str);
#endif
