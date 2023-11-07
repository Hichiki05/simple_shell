#include "main.h"

/*
*read - a fonction the read the user input
@command: a string
@size: the size of the command
*/

char read(void)
{
	char *sent = NULL;
	size_t lent = 0;
	ssize_t i;

	if (isatty(STDOUT_FILENO))
	write(STDOUT_FILENO, "$ ", 2);
	i = getline(&sent, &lent, stdin);
	if (i == -1)
	{
		free(sent);
		return (NULL);
	}
	return (sent);
}
