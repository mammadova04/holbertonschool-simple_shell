#include "main.h"

/**
 * find_file - finds file location in path variables
 * @command: user input
 * @lk: is the flag for is this command use path or not
 * Return: modified user input
 */
char *find_file(char *command, int *lk)
{
    int i = 0, len;
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

    while (path_var[i])
    {
        len = strlen(path_var[i]);
        temp = malloc(len + strlen(command) + 2);
        if (temp == NULL)
            return (NULL);
        strcpy(temp, path_var[i]);
        strcat(temp, "/");
        strcat(temp, command);
        if (!stat(temp, &st))
        {
            (*lk)++;
            errno = 0;
            result = temp;
            break;
        }
        i++;
        free(temp);
    }
    return (result);
}

