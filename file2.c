#include "main.h"
/**
* _positive - the fnct
* @srtr: the string
* Return: a value
*/
int _positive(char *srtr)
{
	int i;

	if (!srtr)
		return (0);
	for (i = 0; srtr[i]; i++)
	{
		if (srtr[i] < '0' || srtr[i] > '9')
			return (0);
	}
	return (1);
}
