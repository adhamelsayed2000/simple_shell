#include "shell.h"

int main()
{
	char *str;
	char *token;
	str = _stdup("this	is\t	EGYPT\n");
	token = strtok(str, " \t\n");
	while (token)
	{
		printf("%s\n" , token);
		token = strtok(NULL, " \t\n");
	}

	return (0);
}



