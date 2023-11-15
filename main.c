#include "shell.h"

/**
 * main - simple shell
 * @argc: number of passed arguments
 * @av: argument array
 *
 * Return: always 0
 */

int main(int ac, char **argv)
{
	char *line = NULL;
	/*char **command = NULL;*/
	int status = 0;
	(void) ac;
	(void) argv;

	while(1){
		line = read_line();
		if (line == NULL)
		{
			return (status);
		}
		printf("%s\n", line);
		/*command = tokenizer(line);
		status = _execute(command, argv);*/
	}
}
