#include "shell.h"

/**
 * _noninteractive - perrorm actions in case of non ionteractive mode
 * @av: program arguments
 */

void _noninteractive(char **av)
{
	char *line = NULL, **tokens = NULL;
	size_t n = 0;

	getline(&line, &n, stdin);
	line[strcspn(line, "\n")] = '\0';
	tokens = tokenizer(line);
	tokens[0] = get_cmd_path(tokens[0]);
	executer(tokens, av);
	_freetokens(tokens);
	free(line);
	return; }
