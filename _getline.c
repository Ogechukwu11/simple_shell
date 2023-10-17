#include "test.h"
/**
 * _getline - Read a line from a file descriptor
 * @lineptr: Pointer to a pointer to the line buffer
 * @n: Pointer to the size of the line buffer
 * @fd: File descriptor to read from
 *
 * Return: 0 (success)
 */
ssize_t _getline(char **lineptr, size_t *n, int fd)
{
	char *temp;
	char c;
	size_t i = 0, j, initial_buffer_size = 128;

	if (*lineptr == NULL || *n == 0)
	{
		*n = initial_buffer_size;
		*lineptr = (char *)malloc(*n);
		if (*lineptr == NULL)
		{
			perror("malloc failed");
			return (-1);
		}
	}
	while (read(fd, &c, 1) == 1 && c != '\n')
	{
		(*lineptr)[i++] = c;
		if (i == *n)
		{
			*n *= 2;
			temp = (char *)malloc(*n);
			if (temp == NULL)
			{
				perror("malloc failed");
				return (-1);
			}
			for (j = 0; j < i; j++)
			{
				temp[j] = (*lineptr)[j];
			}
			free(*lineptr);
			*lineptr = temp;
		}
	}
	if (c == MY_EOF && i == 0)
	{
		return (-1);
	}
	(*lineptr)[i] = '\0';
	return (i);
}
