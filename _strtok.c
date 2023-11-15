#include "main.h"

/**
 * _strtok - tokenize a string into smaller pieces
 * @str: The string to be tokenized
 * @delimiters: A string containing a set of delimiter characters
 *
 * Return: a pointer to the next token in the string.
 * If there are no more tokens, it returns NULL.
 */

char *_strtok(char *str, const char *delimiters)
{
	return (strtok(str, delimiters));
}
