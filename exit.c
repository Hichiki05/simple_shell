#include "main.h"

int _myexit(info_t *shell)
{
    char *endptr;

    if (shell->argv[1])
    {
        long exit_status = strtol(shell->argv[1], &endptr, 10);
        if (*endptr != '\0')
        {
            shell->status = 2;
            fprintf(stderr,"invalid argument: %s\n", shell->argv[1]);
            return (-1);
        }
        shell->err_num = (int)exit_status;
    }
    else
    {
        shell->err_num = -1;
    }
    exit(shell->err_num);
}

int main(int argc, char *argv[])
{
    info_t shell = {0, 0, argv};

    _myexit(&shell);

    return (0);
}