#ifndef MAIN_H
#define MAIN_H

/**
*the header file
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <stdbool.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <errno.h>
#include <fcntl.h>

#define SEP " \t\n"
extern char **environ;

char read(void);
int execute(char **command, char **argv);
void free(char **mess);
char **token(char *sent);

#endif