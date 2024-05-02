#include "main.h"

char **path_var;

/**
 * find_file - finds file location in path variables
 * @command: user input
 * @lk: flag for whether this command uses path or not
 *
 * Return: modified user input
 */
char *find_file(char *command, int *lk)
{
    int i = 0;
    int max_len = 0;
    int j;
    char *temp, *result = NULL;
    struct stat st;

    if (command[0] == '/' || command[0] == '.')
    {
        if (!stat(command, &st))
        {
            result = strdup(command);
            if (result != NULL)
                (*lk)++;
        }
        return (result);
    }

    if (!path_var)
        return (NULL);

    for (j = 0; path_var[j] != NULL; j++)
        max_len += strlen(path_var[j]) + strlen(command) + 2;

    temp = malloc(max_len);
    if (temp == NULL)
        return (NULL);

    while (path_var[i])
    {
        strcpy(temp, path_var[i]);
        strcat(temp, "/");
        strcat(temp, command);
        if (!stat(temp, &st))
        {
            (*lk)++;
            errno = 0;
            result = strdup(temp);
            break;
        }
        i++;
    }

    free(temp);
    return result;
}

