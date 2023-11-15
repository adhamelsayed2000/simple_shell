#include "shell.h"

/**
 * get_cmd_path - get the path of passed command
 * @cmd: thr command
 *
 * Return: the command path if exists, Null is case of not found
 */

CommandResult get_cmd_path(char *cmd)
{
	char *pathvar = NULL, *pathcpy = NULL, *token, *filepath;
	int filepathlen = 0;
	struct stat st;
	CommandResult result;

	result.path = NULL;
	result.found = 0;
	if (cmd == NULL)
		return (result);
	pathvar = getenv("PATH");
	result.path = strdup(cmd);
	if (stat(result.path, &st) == 0)
	{
		result.found = 1;
		return (result); }
	if (pathvar == NULL)
		return (result);
	pathcpy = strdup(pathvar);
	token = _strtok(pathcpy, ":");
	while (token != NULL)
	{
		filepathlen = strlen(cmd) + strlen(token) + 2;
		filepath = (char *)malloc(filepathlen * sizeof(char));
		if (filepath == NULL)
		{
			free(result.path);
			free(pathcpy);
			return (result); }
		snprintf(filepath, filepathlen, "%s/%s", token, cmd);
		if (stat(filepath, &st) == 0)
		{
			free(result.path);
			result.path = filepath;
			result.found = 1;
			free(pathcpy);
			return (result); }
		free(filepath);
		token = _strtok(NULL, ":"); }
	free(pathcpy);
	return (result); }
