#include "main.h"
/**
*main - the main fonction for the simple shell project
*/

int main(void)
{
	char command[200];

	while (1)
	{
		prompt();
		read(command, sizeof(command));
		execute(command);
	}

}
