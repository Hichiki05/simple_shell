#include "main.h"

/*
*read - a fonction the read the user input
@command: a string
@size: the size of the command
*/

void read(char *command, size_t size)
{
	if (fgets(command, size, stdin) == NULL)
	{
		if (feof(stdin))
		{
			print("\n");
			exit(SUCCESS);
		}
		else
		{
			print("FAILURE").
		}
	}
	char *newline = strchr(command, '\n');
	if (newline != NULL)
	{
		*newline = '\0';
	}
}
