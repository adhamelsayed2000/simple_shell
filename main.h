#ifndef MAIN_H
#define MAIN_H
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
extern char **environ;
char **tokenizer(char *str);
void executer(char **args, char **av);
char *get_cmd_path(char *cmd);
void _freetokens(char **tokens);
#endif
