#include "main.h"

/**
* _build - a fonct
* @command: a string
* Return: a value
*/

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

/**
* handle_built - the fnct
* @command: a para
* @argv: the argv
* @status: a status
* @index: an int
*/
void handle_built(char **command, char **argv, int *status, int index)
{
	if (_strcmp(command[0], "exit") == 0)
		_exit_all(command, argv, status, index);

	else if (_strcmp(command[0], "env") == 0)
		_print_env(command, status);
}

/**
* _exit_all - a fnct
* @command: a para
* @argv: a para
* @status: a para
* @index: a para
* Return: a value
*/
void _exit_all(char **command, char **argv, int *status, int index)
{
	int i;
	int value = (*status);
	char *indx, sent[] = ": exit: Illegal number: ";

	if (command == NULL)
		return;
	if (command[1])
	{
		if (_positive(command[1]))
		{
			value = _atoi(command[1]);
		}
		else
		{
			indx = _itoa(index);
			write(STDERR_FILENO, argv[0], _strlen(argv[0]));
			write(STDERR_FILENO, ": ", 2);
			write(STDERR_FILENO, indx, _strlen(indx));
			write(STDERR_FILENO, sent, _strlen(sent));
			write(STDERR_FILENO, command[1], _strlen(command[1]));
			write(STDERR_FILENO, "\n", 1);
			free(indx);
			for (i = 0; command[i]; i++)
			{
				free(command[i]);
				}
	free(command);
			return;
		}
	}
	for (i = 0; command[i]; i++)
	{
		free(command[i]);
	}
	free(command);
	exit(value);
}

/**
* _print_env - the fnct
* @command: a para
* @status: a para
* Return: a value
*/
void _print_env(char **command, int *status)
{
	int i;

	if (command == NULL)
	{
		(*status) = 0;
		return;
	}

	for (i = 0; environ[i]; i++)
	{
		write(STDOUT_FILENO, environ[i], _strlen(environ[i]));
		write(STDOUT_FILENO, "\n", 1);
	}
	for (i = 0; command[i]; i++)
	{
		free(command[i]);
	}
	free(command);
	(*status) = 0;
}
