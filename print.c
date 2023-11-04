#include "main.h"

/**
*print - the fonction that print the output_input_erreur message
*@string: a pointer to a string 
*/
void print(const char *string )
{
	write(STDOUT_FILENO, string, strlen(string));
}code pointer