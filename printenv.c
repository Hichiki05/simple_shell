#include "main.h"


void print_env(info_t *info)
{
    int i = 0;

    while(environ[i])
    {
        write(STDOUT_FILENO, environ[i], _strlen(environ[i]));
        write(STDOUT_FILENO, "\n", 1);
        i++;
    }
    info->args[0] = NULL;
}