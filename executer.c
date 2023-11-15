#include "shell.h"

/**
 * executer - execute the command using execve function
 * @args: the array that contain command and arguments
 * @argv: command line arguments
 *
 * Return: 126 in case of execuve failure
 */

int executer(char **args, char **argv)
{
	if (args == NULL)
		return (0);
	if (execve(args[0], args, environ) == -1)
	{
		perror(argv[0]);
		return (126); }
return (0); }
