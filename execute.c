#include "main.h"

/*
* execute - the fonction
* @command: the command
* @argv: the arguments strings
* Return: the status nmbr
*/

int execute(char **command, char **argv)
{
	pid_t child_proc;
	int status;

	child_proc = fork();
	if (child_proc == 0)
	{
		if (execve(command[0], command, environ) == -1)
		{
			perror(argv[0]);
			_free(command);
			exit(0);
		}
	}
	else
	{
		waitpid(child_proc, &status, 0);
		free(command);
	}
	return(WEXITSTATUS(status));
}
