#include "main.h"
/**
* path - the fonction that checks for the path
* @sent: the command
* Return: the path
*/
char *_path(char *sent)
{
	char *env, *full, *dirc;
	int i;
	struct stat s;

	for (i = 0; sent[i]; i++)
	{
		if (sent[i] == '/')
		{
			if (stat(sent, &s) == 0)
			{
				return (_strdup(sent));  }
			return (NULL);  }
	}
	env = _env("PATH");
	if (!env)
	{
		return (NULL);  }
		dirc = strtok(env, ":");
		while (dirc)
	{
		full = malloc(_strlen(dirc) + _strlen(sent) + 2);
		if (full)
		{
			_strcpy(full, dirc);
			_strcat(full, "/");
			_strcat(full, sent);
			if (stat(full, &s) == 0)
			{
				free(env), env = NULL;
				return (full);  }
			free(full), full = NULL;

			dirc = strtok(NULL, ":");  }
	}
	free(env), env = NULL;
	return (NULL);  }
