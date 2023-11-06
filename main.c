#include "main.h"

/**
 * main - simple shell
 * @argc: number of passed arguments
 * @av: argument array
 *
 * Return: always 0
 */

int main(__attribute__((unused))int argc, char **av)
{
	char *prompt = "$ ", *line = NULL, **tokens = NULL;
	int status;
	size_t n = 0;
	ssize_t rby;
	pid_t pid;
	struct stat st;

	if (!isatty(STDIN_FILENO))
	{
		rby = getline(&line, &n, stdin);
		if (rby > 0 && line[rby - 1] == '\n')
		{
			line[rby - 1] = '\0';
			rby--; }
		tokens = tokenizer(line);
		tokens[0] = get_cmd_path(tokens[0]);
		executer(tokens, av);
		_freetokens(tokens); }
	else
	{

		while (1)
		{
			printf("%s", prompt);
			rby = getline(&line, &n, stdin);
			if (rby > 0 && line[rby - 1] == '\n')
			{
				line[rby - 1] = '\0';
				rby--; }
			if (rby == EOF || rby == '\0' || line[0] == '\n')
				break;
			tokens = tokenizer(line);
			tokens[0] = get_cmd_path(tokens[0]);
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
			printf("\n"); }
	free(line);
	return (0); }
