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

extern char **environ;
char **tokenizer(char *str);
void executer(char **args, char **av);
char *get_cmd_path(char *cmd);
void _freetokens(char **tokens);
void _noninteractive(char **);
void _interactivemode(char **av);
void parse_command(char* input, char** args);
#endif
