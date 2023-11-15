#include "shell.h"

/**
 * exit_error - exit in case of passed number is negative
 * @cmd_exit: passed command
 * @argv: command line arguments
 *
 * Return: always 2
 */

int exit_error(char **cmd_exit, char **argv)
{
	write(STDERR_FILENO, argv[0], _strlen(argv[0]));
	write(STDERR_FILENO, ": ", 2);
	write(STDERR_FILENO, "1: exit: Illegal number: ", 25);
	write(STDERR_FILENO, cmd_exit[1], _strlen(cmd_exit[1]));
	write(STDERR_FILENO, "\n", 1);
	return (2);
}
