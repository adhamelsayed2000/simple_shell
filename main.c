#include "shell.h"

/**
 * main - simple shell
 * @argc: number of passed arguments
 * @av: argument array
 *
 * Return: always 0
 */

int main(__attribute__((unused))int argc, char **av)
{
	if (!isatty(STDIN_FILENO))
		_noninteractive(av);
	else
		_interactivemode(av);
	return (0); }
