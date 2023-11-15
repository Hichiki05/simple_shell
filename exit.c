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

	if (shell->args[1] != NULL)
	{
        status = shell->status;
        free_shell(shell);
        exit(status);
    }
		else if (valid_num(shell->args[1]))
		{
			status = _atoi(shell->args[1]);
            if (status == -1)
			{
				write_error(shell, "wrong integer:");
				write(STDERR_FILENO, shell->args[1], _strlen(shell->args[1]));
				write(STDERR_FILENO, "\n", 1);
				shell->status = 2;
				return;
			}
            free_shell(shell);
            exit(status);
        }
	else
	{
	shell->status = 2;
	write_error(shell, "wrong integer:");
	write(STDERR_FILENO, shell->args[1], _strlen(shell->args[1]));
	write(STDERR_FILENO, "\n", 1);
	return;
	}
}
