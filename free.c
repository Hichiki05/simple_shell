#include "main.h"

void _free(char **mess)
{
	int i;
	if (!mess)
	{
		return;
	}
	for (i = 0; mess[i]; i++)
	{
		free(mess[i]);
		mess[i] = NULL;
	}
	free(mess),mess = NULL;
}
