#include "shell.h"

/*char **tokenizer(char *line)
{
	char *token = NULL, *tmp = NULL;
	char **command = NULL;
	int cpt = 0, i = 0;
	
	if (!line)
	{
		return(NULL)
	}
	tmp = _stdup(line);
	token = strtok(tmp, DELIM);
	while (token)
	{
		cpt++;
		token = strtok(NULL, DELIM);
	}
	free(tmp), tmp = NULL ;

	command = malloc(sizeof(char *) * (cpt + 1));
	if(!command)
	{
		free(line);
		return (NULL);
	}

	token = strtok(line, DELIM);
        while (token)
        {
                command[i] = token;
                token = strtok(NULL, DELIM);
		i++;
        }
	free (line), line = NULL;
	command [i] = NULL;
	return (command);
}*/

/**
 * tokenizer - splits a string
 * @str: the string to be splitted
 *
 * Return: an array of each word of the string and null in case of failure
 */

char **tokenizer(char *str)
{
	char **wrds = NULL, *strcopy, *token;
	int count = 0, i;

	strcopy = strdup(str);
	if (strcopy == NULL)
		return (NULL);
	token = _strtok(strcopy, " ");
	while (token != NULL)
	{
		wrds = (char **)realloc(wrds, (count + 1) * sizeof(char *));
		if (wrds == NULL)
		{
			free(strcopy);
			return (NULL); }
		wrds[count] = strdup(token);
		if (wrds[count] == NULL)
		{
			free(strcopy);
			for (i = 0; i < count; i++)
				free(wrds[i]);
			free(wrds);
			return (NULL); }
		count++;
		token = _strtok(NULL, " "); }
	free(strcopy);
	wrds = (char **)realloc(wrds, (count + 1) * sizeof(char *));
	if (wrds == NULL)
	{
		for (i = 0; i < count; i++)
			free(wrds[i]);
		free(wrds);
		return (NULL); }
	wrds[count] = NULL;
	return (decisionmaker(wrds)); }
