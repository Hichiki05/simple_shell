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
	int status = 0, index = 0;
	int i;
	(void) ac;

	while (1)
	{
		sent = _read();
		if (sent == NULL)
		{
			if (isatty(STDIN_FILENO))
			write(STDOUT_FILENO, "\n", 1);
			free(sent);
			return (status);

		}
		index++;

		command = _token(sent);
		if (!command)
		{
			free(sent);
			continue;
		}
if (_build(command[0]))
	handle_built(command, argv, &status, index);
else
{
	status = _execute(command, argv, index);
}

for (i = 0; command[i]; i++)
{
	free(command[i]);
}
free(command);
free(sent);
	}
}
