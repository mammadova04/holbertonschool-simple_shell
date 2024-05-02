#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <errno.h>
#include "main.h"

char *try_path(char *command, char *path, int *lk);

/**
 * find_file - Finds the location of a file in path variables.
 *
 * @command: User input specifying the file.
 * @path_var: Array of path variables.
 * @lk: Flag indicating whether this command uses path or not.
 *
 * This function searches for the specified file in the provided path
 * variables. If the file is found, it returns the path to the file;
 * otherwise, it returns NULL.
 *
 * Return: Pointer to the path of the file if found, otherwise NULL.
 */
char *find_file(char *command, char **path_var, int *lk)
{
	int i = 0;
	char *result = NULL;
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
		result = try_path(command, path_var[i], lk);
		if (result != NULL)
			return (result);
		i++;
	}

	return (NULL);
}

char *try_path(char *command, char *path, int *lk)
{
	char *temp = NULL;
	char *result = NULL;
	struct stat st;

	int max_len = strlen(path) + strlen(command) + 2;

	temp = malloc(max_len);

	if (temp == NULL)
		return (NULL);

	strcpy(temp, path);
	strcat(temp, "/");
	strcat(temp, command);

	if (!stat(temp, &st))
	{
		(*lk)++;
		errno = 0;
		result = strdup(temp);
	}

	free(temp);
	return (result);
}

int main(void)
{
	char **path_var = {"path1", "path2", NULL};
	int lk = 0;
	char *command = "test.txt";
	char *result = find_file(command, path_var, &lk);

	if (result != NULL)
	{
		printf("File found at: %s\n", result);
		free(result);
	}
	else
	{
		printf("File not found.\n");
	}
	return (0);
}

