#include "main.h"

/**
* _env - the fonction that searshes for the env variables
* @var: the  variable we want to searsh
* Return: the value of the variable
*/
char *_env(char *var)
{
	char *tmp, *tok, *tok2, *env;
	int i;

	for (i = 0; environ[i]; i++)
	{
		tmp = _strdup(environ[i]);
		tok = strtok(tmp, "=");

		if (_strcmp(tok, var) == 0)
		{
			tok2 = strtok(NULL, "\n");
			env = _strdup(tok2);
			free(tmp), tmp = NULL;
			return (env);
		}
		free(tmp), tmp = NULL;
	}
	return (NULL);
}
