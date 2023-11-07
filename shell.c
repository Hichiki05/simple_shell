#include "main.h"
/**
*main - the main fonction for the simple shell project
*/

int main(int ac, char **argv)
{
	char *sent = NULL;
	char **command = NULL;
	char status = 0;
	(void) ac;

	while (1)
	{
		sent = read();
		if (sent == NULL)
		{
			if (isatty(STDOUT_FILENO))
			write(STDOUT_FILENO, "\n", 1);
			return (status);
		}

		command = token(sent);
		if (!command)
		continue;

	status = execute(command, argv);
}
}