#include "main.h"

/**
 * executer - execute the command using execve function
 * @args: the array that contain command and arguments
 * @av: program arguments
 */

void executer(char **args, char **av)
{
	char *cmd = NULL;
	int val;

	if (args == NULL)
		return;
	cmd = args[0];
	val = execve(cmd, args, environ);
	if (val == -1)
		perror(av[0]);
}
