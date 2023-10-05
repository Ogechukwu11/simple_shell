#include "test.h"

/**
 * cmd_parse - To parse the input
 * @cmd: The command to parse
 * @av: The argument
 * Return: void
 */
void cmd_parse(char *cmd, char **av)
{
	char *token;
	int count = 0;

	token = strtok(cmd, " ");
	while (token != NULL)
	{
		av[count++] = token;
		token = strtok(NULL, " ");
	}

	av[count] = NULL;
}

/**
 * _minenv - prints current environment
 * Return: Always 0
 */
int _minenv(void)
{
	char **env = environ;

	if (environ == NULL)
	{
		_OA_printer("Environment not available\n");
		return (-1);
	}
	for (; *env != NULL; env++)
	{
		_OA_printer(*env);
		_OA_printer("\n");
	}
	return (0);
}

/**
 * _strtok - Tokenizes a string.
 * @str: The string to be tokenized.
 * @delimiter: A string containing all possible delimiters.
 *
 * Return: A pointer to the next token, or NULL if no more tokens are found.
 */
char *_strtok(const char *str, const char *delimiter)
{
	static const char *token_start;
	const char *start = str ? str : token_start;
	const char *end;
	char *token;

	if (str == NULL || delimiter == NULL)
		return (NULL);
	if (start == NULL)
		return (NULL);
	while (*start != '\0' && str_chr(delimiter, *start) != NULL)
	{
		start++;
	}
	if (*start == '\0')
	{
		token_start = NULL;
		return (NULL);
	}
	end = start;
	while (*end != '\0' && str_chr(delimiter, *end) == NULL)
	{
		end++;
	}
	if (*end == '\0')
	{
		token_start = NULL;
	}
	else
	{
		token_start = end + 1;
	}
	token = _sdup(start);
	printf("token = %s\n", token);
	return (token);
}
