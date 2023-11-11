#include "main.h"

/**
* _read - a fonction the read the user input
* Return: the sent
*/

char *_read(void)
{
	char *sent = NULL;
	size_t lent = 0;
	ssize_t i;

	if (isatty(STDIN_FILENO))
	write(STDOUT_FILENO, "$ ", 2);

	i = getline(&sent, &lent, stdin);
	if (i == -1)
	{
		free(sent), sent = NULL; 
		return (NULL);
	}
	return (sent);
}
