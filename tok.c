#include "main.h"


char **token(char *sent)
{
	char *tok = NULL, *tmp = NULL;
	char **command = NULL;
	int count = 0, i = 0;

	if (!sent)
	{
		return (NULL);
	}
	tmp = _strdup(sent);

	tok = strtok(tmp,SEP);
	if (tok == NULL)
	{
		_free(sent);
		_free(tmp);
		return (NULL);
	}

	while (tok)
	{
		count++;
		tok = strtok(NULL, SEP);
	}
	_free(tmp);

	command = malloc(sizeof(char *) * (count + 1));
	if (!command)
	{
		_free(sent);
		return (NULL);
	}

	tok = strtok(sent, SEP);

	while (tok)
	{
		command[i] = _strdup(tok);
		tok = strtok(NULL, SEP);
		i++;
	}
	_free(sent);
	command[i] = NULL;
	return (command);
}
