#include "shell.h"

/**
 * _strcmp - compares two strings s1 and s2
 * @s1: The first string
 * @s2: The second string
 *
 * Return: 0, if strings are equal
 * if first string < second string, -1
 * if first string > second string, 1
*/

int _strcmp(const char *s1, const char *s2)
{
	while (*s1 != '\0' && *s2 != '\0')
	{
		if (*s1 != *s2)
		{
			return (*s1 - *s2);
		}
		s1++;
		s2++;
	}
	return (*s1 - *s2);
}
