#include "shell.h"

/**
 * _strlen - get the length of passed string
 * @s: passed string
 *
 * Return: the length of passed string
 */

int _strlen(char *s)
{
	int length = 0, i;

	for (i = 0; s[i] != '\0'; i++)
		length++;

	return (length); }
