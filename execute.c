#include "main.h"

/**
* _execute - the fonction
* @command: the command
* @argv: the arguments strings
* @indx: a counter
* Return: the status nmbr
*/

int _execute(char **command, char **argv, int indx)
{
	char *full_command;
	pid_t child_proc;
	int status;

	full_command = _path(command[0]);
	if (!full_command)
	{
		_error(argv[0], command[0], indx);
		free(command), command = NULL;
		return (127);
	}

	child_proc = fork();
	if (child_proc == -1)
	{
		free(full_command), full_command = 	NULL;
		free(command), command = NULL;
		return (-1);
	}

	if (child_proc == 0)
	{
		if (execve(full_command, command, environ) == -1)
		{
			free(full_command), full_command = NULL;
			free(command), command = NULL;
		}
	}
	else
	{
		waitpid(child_proc, &status, 0);
		free(command), command = NULL;
	}
	free(full_command), full_command = NULL;
	
	return (WEXITSTATUS(status));
}
