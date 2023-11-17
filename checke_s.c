#include "main.h"

int _build(char *command)
{
	char *builds[] = {
		"exit", "env", "setenv", "cd", NULL
	};
	int i;
	for (i = 0; builds[i]; i++)
	{
		if (_strcmp(command, builds[i]) == 0)
		return (1);
	}
	return (0);
}

void handle_built(char **command, char **argv, int *status, int index)
{
	(void) argv;
	(void) index;

	if (_strcmp(command[0], "exit") == 0)
		_exit_all(command, status);
	else if (_strcmp(command[0], "env") == 0)
		_print_env(command, status);
}

void _exit_all(char **command, int *status)
{
	int i;

	for (i = 0; command[i]; i++)
	{
		free(command[i]);
	}

	free(command), command = 0;
	exit(*status);
}

void _print_env(char **command, int *status)
{
	int i;

	for (i = 0; environ[i]; i++)
	{
		write(STDOUT_FILENO, environ[i], _strlen(environ[i]));
		write(STDOUT_FILENO, "\n", 1);
	}
	for (i =0; command[i]; i++)
	{
		free(command[i]);
	}
	free(command), command = 0;
	(*status) = 0;
}
