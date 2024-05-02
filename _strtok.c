#include "main.h"

/**
 * _strtok - Custom strtok implementation
 * @str: String for tokenization
 * @delim: Delimiter
 *
 * Return: Array of tokens
 */
char **_strtok(char *str, char delim)
{
    char **array, *start, *end;
    int i = 0, j = 1, num_tokens = 0;

    if (str == NULL)
        return (NULL);

    while (str[i])
    {
        if (str[i] != delim)
        {
            num_tokens++;
            while (str[i] != delim && str[i])
                i++;
        }
        else
        {
            i++;
        }
    }

    if (num_tokens == 0)
        array = malloc(sizeof(char *));
    else
        array = malloc(sizeof(char *) * (num_tokens + 1));

    if (array == NULL)
        return (NULL);

    i = 0;

    while (str[i])
    {
        if (str[i] != delim)
        {
            start = str + i;
            while (str[i] != delim && str[i])
                i++;
            end = str + i;
            *end = '\0';
            array[j - 1] = strdup(start);
            *end = delim;
            j++;
        }
        else
        {
            i++;
        }
    }

    array[j - 1] = NULL;
    return (array);
}

