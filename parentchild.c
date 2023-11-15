#include "shell.h"

/**
 * parentchild - makes a child process to execute
 * @tokens: tokanized input
 * @argv: command line arguments
 *
 * Return: exit code in case of error
 */

int parentchild(char **tokens, char **argv)
{
	pid_t pid;
	int status, exit_code = 0;
	CommandResult cm;

	cm = get_cmd_path(tokens[0]);
	free(tokens[0]);
	tokens[0] = cm.path;
	if (cm.found == 0)
	{
		command_error(tokens, argv);
		exit_code = 127; }
	else if (cm.found == 1 && cm.path != NULL)
	{
		if (access(tokens[0], X_OK) == 0)
		{
			pid = fork();
			if (pid == -1)
			{
				perror(argv[0]);
				_freetokens(tokens);
				exit_code = 1;
			}
			else if (pid == 0)
				exit_code = executer(tokens, argv);
			else
			{
				wait(&status);
				if (WIFEXITED(status))
					exit_code = WEXITSTATUS(status);
				else if (WIFSIGNALED(status))
					exit_code = WTERMSIG(status);
				else if (WIFSTOPPED(status))
					exit_code = WSTOPSIG(status);
			}}
		else
		{
			perror(argv[0]);
			exit_code = 126; }}
	return (exit_code);
}
