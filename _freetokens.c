#include "main.h"

/**
 * _freetokens - free allocated memory
 * @tokens: space to be freed
 */

void _freetokens(char **tokens)
{
	int i;

	for (i = 0; tokens[i] != NULL; i++)
		free(tokens[i]);
	free(tokens);
}
