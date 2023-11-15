#include "shell.h"

char *_stdup(const char *str)
{
	char *ptr;
	int i, len = 0;

	if (str == NULL)
	{
		return (NULL);
	}
	while (*str != '\0')
	{
		len++;
		str++;
	}
	str = str - len;
	ptr = malloc(sizeof(char) * (len + 1));
	if (ptr == NULL)
	{
		return (NULL);
	}
	for (i == 0; i <= len; i++)
	{
		ptr[i] = str[i];
	}
	return (ptr);
}
int _stcmp(char *a1, char *a2)
{
	int cmp;
	cmp = (int)*a1 - (int)*a2;
	while (*a1)
	{
		if (*a1 != *a2)
		{
			break;
		}
		a1++;
		a2++;
		cmp = (int)*a1 - (int)*a2;
	}
	return (cmp);
}
int _stlen(char *a)
{
	int len = 0;
	while (a[len])
	{
		len++;
	}
	return (len);
}
char *_stcat(char *dest, char *src)
{
	char *p = dest;
	while(*p)
	{
		p++;
	}
	while (*src)
	{
		*p = *src;
		p++;
		src++;
	}
	*p = *src;
	return (dest);
}
char *_stcpy(char *dest, char *src)
{
	int i =0;

	while(src[i])
	{
		dest[i] = src[i];
		i++;
	}
	 dest[i] = '\0'; // Null-terminate the destination string

    	return dest;	
}
