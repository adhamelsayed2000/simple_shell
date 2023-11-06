#include "main.h"

/**
 * _interactivemode - perform actions in case of interactive mode
 * @av: the program arguments
 */

void _interactivemode(char **av)
{
	char *prompt = "$ ", *line = NULL, **tokens = NULL;
	int status;
	size_t n = 0;
	ssize_t rby;
	pid_t pid;
	struct stat st;

	while (1)
	{
		printf("%s", prompt);
		rby = getline(&line, &n, stdin);
		line[strcspn(line, "\n")] = '\0';
		if (rby == EOF || rby == '\0' || line[0] == '\n')
			break;
		tokens = tokenizer(line);
		tokens[0] = get_cmd_path(tokens[0]);
		if (tokens[0] == NULL)
			continue;
		if (stat(tokens[0], &st) == 0)
		{
			pid = fork();
			if (pid == 0)
				executer(tokens, av);
			else
				wait(&status); }
		else
			executer(tokens, av);
		_freetokens(tokens); }
		printf("\n");
		free(line); }
