#include "main.h"

/**
 * _myexit - exit shell
 * @shell: parameter
*/

void _myexit(info_t *shell)
{

	free_shell(shell);
	exit(shell->status);
}

