#include "shell.h"

/**
 * tokenizer - splits a string
 * @str: the string to be splitted
 *
 * Return: an array of each word of the string and null in case of failure
 */

char **tokenizer(char *str)
{
	char **words = NULL, *strcopy, *token;
	int count = 0, i;

	strcopy = strdup(str);
	if (strcopy == NULL)
	{
		fprintf(stderr, "Memory Allocation Failure");
		return (NULL); }
	token = strtok(strcopy, " ");
	while (token != NULL)
	{
		words = (char **)realloc(words, (count + 1) * sizeof(char *));
		if (words == NULL)
		{
			free(strcopy);
			fprintf(stderr, "Memory Allocation Failure");
			return (NULL); }
		words[count] = strdup(token);
		if (words[count] == NULL)
		{
			free(strcopy);
			for (i = 0; i < count; i++)
				free(words[i]);
			free(words);
			fprintf(stderr, "Memory Allocation Failure");
			return (NULL); }
		count++;
		token = strtok(NULL, " "); }
	free(strcopy);
	words = (char **)realloc(words, (count + 1) * sizeof(char *));
	if (words == NULL)
	{
		for (i = 0; words[i] != NULL; i++)
			free(words[i]);
		free(words);
		fprintf(stderr, "Memory Allocation Failure");
		return (NULL); }
	words[count] = NULL;
	return (words); }
