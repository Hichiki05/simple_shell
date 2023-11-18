#include "main.h"
#define BUFFER_SIZE 2048
#define READ_SIZE 1024

/**
 * realo_line - reallocate the line buffer
 * @line: line to be buffered
 * @oldsize: old size
 * @newsize: new size
 *
 * Return: new allocated buffer
 */

char *realo_line(char **line, unsigned int oldsize, unsigned int newsize)
{
	char *newline = NULL;
	unsigned int i;

	newline = malloc(newsize);
	if (newline)
	{
		for (i = 0; i < oldsize; i++)
			newline[i] = (*line)[i];
		free(*line);
		*line = newline;
	}
	return (newline);
}

/**
 * _getline - gets a line of chars
 * @info: parameters
 *
 * Return: number of read chars
 */

int _getline(info_t *info)
{
	char *line = NULL;
	static unsigned int buffsize = BUFFER_SIZE;
	char *writehead = line;
	unsigned int len;

	line = malloc(BUFFER_SIZE);
	do {
		len = read(0, writehead, BUFFER_SIZE);
		if (len == 0)
			break;
		writehead += len;
		if (writehead >= (line + BUFFER_SIZE - 1 - READ_SIZE))
		{
			line = realo_line(&line, buffsize, buffsize * 2);
			buffsize *= 2;
		}
		} while (*(writehead - 1) != '\n');

		free(info->buffer);
		info->buffer = line;
		if (len == 0)
			return (-1);
		return (_strlen(info->buffer));
}



