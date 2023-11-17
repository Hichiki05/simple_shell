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
 * SEP - A delimiter for tokenization
 */

#define SEP " \t\n"
extern char **environ;
/**
 * struct info_t - Structure for shell information
 * @status: Status of the shell
 * @args: Arguments for the shell
 */

typedef struct info_t
{
	int status;
	char **args;
} info_t;

int _atoi(char *str);
void free_shell(info_t *shell);
void write_error(info_t *shell, const char *msg);
int valid_num(char *param);
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
int _myexit(info_t *shell);
void handle_built(char **command, char **argv, int *status, int indx);
int _build(char *command);
void _exit_all(char **command, char **argv, int *status, int index);
void _print_env(char **command, int *status);
int _positive(char *srtr);
int _atoi(char *srtr);

#endif
