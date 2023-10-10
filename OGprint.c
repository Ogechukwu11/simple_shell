#include "test.h"

/**
 * _OA_printer - To print to the standard output
 * @letters: The message to print to the stdout
 * Return: void
 */
void _OA_printer(const char *letters)
{
	if (isatty(STDOUT_FILENO))
	{
		write(STDOUT_FILENO, letters, _len(letters));
	}
}
