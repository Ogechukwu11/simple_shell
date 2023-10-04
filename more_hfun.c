#include "test.h"

/**
 * * _len - Calculate the length of a string.
 * @str: The string to be measured.
 * Return: The length of the string.
 */
size_t _len(const char *str)
{
	size_t len = 0;

	while (str && str[len])
		len++;
	return (len);
}
