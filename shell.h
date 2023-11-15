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

#define MAX_PATH_LENGTH 1024
#define MAX_INPUT_LENGTH 1024

char *read_line(void);

char *_stdup(const char *str);
int _stcmp(char *a1, char *a2);
int _stlen(char *a);
char *_stcat(char *dest, char *src);
char *_stcpy(char *dest, char *src);
char **sttow(char *, char *);
char **sttow2(char *, char);
#endif
