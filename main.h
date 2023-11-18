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
/**
* SEP - a delimitor
*/

#define SEP " \t\n"
extern char **environ;

/**
 * struct info_t - Structure for shell information
 * @status: Status of the shell
 * @argv: Arguments for the shell
 * @err_num: a para
 */

typedef struct info_t
{
	int status;
	int err_num;
	char **argv;
	char *buffer;
} info_t;

int _getline(info_t *info);
char *realo_line(char **line, unsigned int size1, unsigned int size2);
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

#endif
