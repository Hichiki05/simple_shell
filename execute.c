#include "main.h"

/*
* execute - the fonction that execute the command
* @command: a pointer to a string
*/
void execute(const char *command)
{
	pid_t child_pid = fork();

	if (child_pid == -1)
	{
		print("forking error.\n");
		exit (FAILURE);
	}
	else if (child_pid == 0)
	{
		char *tok_string[150];
		int count = 0;
		int *token = strtok((char *)command, " ");

		while (token != NULL)
		{
			tok_string[count++] = token;
			token = strtok(NULL, " ");
		} 
		tok_string[count] = NULL;

		char *const envp[] = {NULL};

		execve(tok_string[0], tok_string, envp);
	
		print("fail to execute.\n");
		exit(FAILURE);
	}
	else
	{
		wait(NULL);
	}
}
