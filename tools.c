#include "main.h"

/**
* _error - the fonction
* @name: the name
* @comm: the command
* @indx: the index
* Return: void
*/
void _error(char *name, char *comm, int indx)
{
	char *index, sent[] = ": not found\n";

	index = _itoa(indx);

	write(STDERR_FILENO, name, _strlen(name));
	write(STDERR_FILENO, ": ", 2);
	write(STDERR_FILENO, index, _strlen(index));
	write(STDERR_FILENO, ": ", 2);
	write(STDERR_FILENO, comm, _strlen(comm));
	write(STDERR_FILENO, sent, _strlen(sent));

	free(index), index = NULL;
}

/**
* _itoa - the fonction
* @i: an integer
* Return: a buffer
*/
char *_itoa(int i)
{
	char buff[20];
	int n = 0;

	if (i == 0)
	{
		buff[n++] = '0';
	}
	else
	{
		while (i > 0)
		{
			buff[n++] = (i % 10) + '0';
			i /= 10;
		}
	}
	buff[n] = '\0';
	reverse_str(buff, n);

	return (_strdup(buff));
}

/**
* reverse_str - a fonction that reverse the strings
* @string: the string
* @lent: the lent
* Return: NULL
*/
void reverse_str(char *string, int lent)
{
	char tmp;
	int first = 0;
	int last = lent - 1;

	while (first < last)
	{
		tmp = string[first];
		string[first] = string[last];
		string[last] = tmp;
		first++;
		last--;
	}
}
