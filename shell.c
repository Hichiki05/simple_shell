#include "main.h"
/**
* main - the main fonction for the simple shell project
* @ac: argc
* @argv: the arguments and the name of the program
* Return: NULL
*/


int main(int ac, char **argv)
{
	char *sent = NULL;
	char **command = NULL;
	int status = 0, indx = 0;
	(void) ac;

	while (1)
	{
		sent = _read();
		if (sent == NULL)
		{
			if (isatty(STDIN_FILENO))
			write(STDOUT_FILENO, "\n", 1);
			return (status);
		}
		indx++;
		command = _token(sent);
		if (!command)
		continue;

status = _execute(command, argv, indx);
free(sent);
free(command);
}

return (status);
}
