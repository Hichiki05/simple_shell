#include "main.h"

#define BUF_SIZE 1024

/**
 * _getline - reads a whole line line from fd, sorts the address
 * of the buffer storing the text in *lineptr.
 * the buffer is null terminated.
 * @lineptr: pointer storing the address for the line
 * @n: size of allocating lineptr
 * @fd: file descriptor
 *
 * Return:size of the line from fd
 */

ssize_t _getline(char **lineptr, size_t *n, int fd)
{
	static char buf[BUF_SIZE];
	static size_t buf_index;
	static size_t num_read;
	ssize_t line_index = 0;

	if (*lineptr == NULL)
	{
		*n = BUF_SIZE;
		*lineptr = malloc((*n) * sizeof(char));

	}

	while (1)
	{
		if (buf_index >= num_read)
		{
			num_read = read(fd, buf, BUF_SIZE);
			buf_index = 0;

			if (num_read <= 0)
				break;
		}
		if (*n - 1 <= (size_t)line_index)
		{
			*n *= 2;
			*lineptr = realloc(*lineptr, *n);

		}

		(*lineptr)[line_index] = buf[buf_index];
		line_index++;
		buf_index++;

		if ((*lineptr)[line_index - 1] == '\n')
		break;
	}
	if (num_read <= 0 && line_index == 0)
		return (-1);
	(*lineptr)[line_index] = '\0';
	return (line_index);
}
