#include "main.h"

/**
 * _myexit - function to exit
 * @shell: parameter
*/

void _myexit(info_t *shell)
{
	int status = shell->status;

	free_shell(shell);
	exit(status);
}
