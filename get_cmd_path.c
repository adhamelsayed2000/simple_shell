#include "main.h"

/**
 * get_cmd_path - get the path of passed command
 * @cmd: thr command
 *
 * Return: the command path if exists, Null is case of not found
 */

char *get_cmd_path(char *cmd)
{
    char *pathvar, *pathcpy, *token, *filepath;
    int cmdlen = strlen(cmd), tokenlen;
    struct stat st;

    if (cmd == NULL)
    {
        fprintf(stderr, "Command name is NULL\n");
        return (NULL);
    }

    pathvar = getenv("PATH");
    if (pathvar == NULL)
    {
        fprintf(stderr, "PATH environment variable is not set\n");
        return (NULL);
    }

    pathcpy = strdup(pathvar);
    if (pathcpy == NULL)
    {
        perror("Error");
        return (NULL);
    }

    token = strtok(pathcpy, ":");
    while (token != NULL)
    {
        tokenlen = strlen(token);
        filepath = (char *)malloc((cmdlen + tokenlen + 2) * sizeof(char));

        if (filepath == NULL)
        {
            free(pathcpy);
            perror("Error");
            return (NULL);
        }

        strcpy(filepath, token);
        strcat(filepath, "/");
        strcat(filepath, cmd);
        strcat(filepath, "\0");

        if (stat(filepath, &st) == 0)
        {
            free(pathcpy);
            return (filepath);
        }

        free(filepath);
        token = strtok(NULL, ":");
    }

    free(pathcpy);
    
    if (stat(cmd, &st) == 0)
        return (cmd);

    return (NULL);
}
