#include "main.h"

/**
 * _atoi - function to convert string to int
 * @str: string to be converted
 * Return: converted int
*/
int _atoi(char *str)
{
	int result = 0;
	int sign = 1;

	if (*str == '-')
	{
		sign = -1;
		str++;
	}

	while (*str >= '0' && *str <= '9')
	{
		result = result * 10 + (*str - '0');
		str++;
	}
	return (sign * result);
}

/**
 * write_error - function to write an error message
 * @shell: pointer to info_t struct
 * @msg: message to be written
*/

void write_error(info_t *shell, const char *msg)
{
	(void)shell;
	write(STDERR_FILENO, msg, _strlen(msg));
}

/**
 * free_shell - function to free memory
 * @shell: pointer to info_t struct to be freed
*/

void free_shell(info_t *shell)
{
	free(shell);
}
