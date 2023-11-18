#include "main.h"

/**
 * _free -  Deallocates a dynamically allocated array of character pointers.
 * @new_argv: The array to be deallocated.
 *
 * Return: void
 */

void _free(char **new_argv)
{
	free(new_argv);
	new_argv = NULL;
}
