#include "test.h"
/**
 * _puts - function that prints a string, followed by a new line
 * @str: String to print
 */
void _puts(char *str)
{
	while (*str != '\0')
	{
		putchar(*str++);
	}
		putchar('\n');
}
