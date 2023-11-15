#include "shell.h"

/**
 * command_error - display an error in case of command not found
 * @tokens: command to be displayed
 * @argv: command line arguments
 */

void command_error(char **tokens, char **argv)
{
	write(STDERR_FILENO, argv[0], _strlen(argv[0]));
	write(STDERR_FILENO, ": 1", 3);
	write(STDERR_FILENO, ": ", 2);
	write(STDERR_FILENO, tokens[0], _strlen(tokens[0]));
	write(STDERR_FILENO, ": not found\n", 12);
}
