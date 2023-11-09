#ifndef MAIN_H
#define MAIN_H


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <errno.h>
#include <fcntl.h>
/*
*SEP: a delimitor
*/

#define SEP " \t\n"
extern char **environ;

char *_read(void);
int execute(char **command, char **argv, int indx);
char **token(char *sent);
char *_env(char *var);
int _strlen(char *s);
int _strcmp(char *s1, char *s2);
char *_strcat(char *dest, char *src);
char *_strcpy(char *dest, char *src);
char *_strdup(const char *str);
char *path(char *sent);
void _error(char *name, char *comm, int indx);
char *_itoa(int i);
void reverse_str(char *string, int lent);

#endif
