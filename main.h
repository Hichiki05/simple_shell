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
#include <limits.h>
/**
* SEP - a macro
*/

#define SEP " \t\n"
extern char **environ;

/**
 * struct info_s - a structure representing status and arguments
 * @status: an integer representing the status
 * @args: a pointer to an array of strings representing arguments
 *
 * Description: This structure is used to store information about the status
 *              of a command and its arguments.
 */
typedef struct info_s
{
int status;
char **args;
} info_t;

int _atoi(char *str);
char *_read(void);
int _execute(char **command, char **argv, int indx);
char **_token(char *sent);
char *_env(char *var);
int _strlen(const char *s);
int _strcmp(char *s1, char *s2);
char *_strcat(char *dest, char *src);
char *_strcpy(char *dest, char *src);
char *_strdup(const char *str);
char *_path(char *sent);
void _error(char *name, char *comm, int indx);
char *_itoa(int i);
void reverse_str(char *string, int lent);
void handle_built(char **command, char **argv, int *status, int indx);
int _build(char *command);
void _exit_all(char **command, char **argv, int *status, int index);
void _print_env(char **command, int *status);
int _build(char *command);
void handle_built(char **command, char **argv, int *status, int index);
void _exit_all(char **command, char **argv, int *status, int index);
void _print_env(char **command, int *status);
int _positive(char *srtr);
int _atoi(char *srtr);
ssize_t _getline(char **lineptr, size_t *n, int fd);

#endif
