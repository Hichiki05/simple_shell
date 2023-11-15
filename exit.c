#include "main.h"

/**
 * valid_num - check if string is a valid number
 * @param: string
 *
 * Return: 0 false or 1 true
*/

int valid_num(char *param)
{
	while (*param)
	{
		if (*param < '0' || *param > '9')
			return (0);
		param++;
	}
	return (1);
}


/**
 * _myexit - function to exit
 * @shell: parameter passed
 *
*/

void _myexit(info_t *shell)
{
	int status = 0;

	if (shell->args[1])
	{
		if (valid_num(shell->args[1]))
		{
			status = _atoi(shell->args[1]);

			if (status == 0 && shell->args[1][0] != '0')
			{
				write_error(shell, "wrong integer:");
				write(STDERR_FILENO, shell->args[1], _strlen(shell->args[1]));
				write(STDERR_FILENO, "\n", 1);
				shell->status = 2;
				return;
            }
                        
			}
	else
	{
	shell->status = 2;
	write_error(shell, "wrong integer");
	write(STDERR_FILENO, shell->args[1], _strlen(shell->args[1]));
	write(STDERR_FILENO, "\n", 1);
	return;
	}
	}

	free_shell(shell);
	exit(status);
}
