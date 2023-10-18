#include "test.h"
/**
 * _puts - function that prints a string, followed by a new line
 * @str: String to print
 */
void _puts(const char *str)
{
	while (*str != '\0')
	{
		_OA_printer(*str++);
	}
		_OA_printer('\n');
}

