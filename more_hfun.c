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

/**
 * _int - To convert the string to an integer
 * @_string: The string to convert to an integer
 * Return: an integer
 */

int _int(char *_string)
{
	int c = 0;
	unsigned int ni = 0;
	int min = 1;
	int isi = 0;

	while (_string[c])
	{
		if (_string[c] == '-')
		{
			min *= -1;
		}
		while (_string[c] >= '0' && _string[c] <= '9')
		{
			isi = 1;
			ni = (ni * 10) + (_string[c] - '0');
			c++;
		}
		if (isi == 1)
		{
			break;
		}
		c++;
	}
	ni *= min;
	return (ni);
}
