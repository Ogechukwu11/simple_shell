#include "test.h"

/**
 * exit_shell - To exit the shell with an integer code
 * @status: The integer code
 * Return: void
 */
void exit_shell(int status)
{
	exit(status);
}

/**
 * is_interactive - To run interactive mode in the shell
 *
 * Return: void
 */
void is_interactive(void)
{
	char *s = NULL;
	char *cmd_argv[MAX_INPUT_LENGTH];
	int exit_status;
	ssize_t byte_read;
	size_t b;

	while (1)
	{
		_OA_printer("simple_shell$ ");
		byte_read = getline(&s, &b, stdin);
		if (byte_read == -1)
			free(s), exit(0);

		if (s[byte_read - 1] == '\n')
			s[byte_read - 1] = '\0';
		cmd_parse(s, cmd_argv);

		if (cmd_argv[0] != NULL)
		{
			if (str_cmp(cmd_argv[0], "exit", _len("exit")) == 0)
			{
				if (cmd_argv[1] != NULL)
				{
					exit_status = _int(cmd_argv[1]);
					free(s), exit_shell(exit_status);
				}
				else
					free(s), exit_shell(0);
			}
			else if (str_cmp(cmd_argv[0], "env", _len("env")) == 0)
				_minenv();
			else
			{
				exit_status = cmd_execute(cmd_argv);
				if (exit_status == -1)
					perror("Command execution failed");
			}
		}
	}
	free(s);
}

/**
 * check_script - A function that checks script
 * @file_name: The name of the script
 * Return: The executable script
 */
int check_script(const char *file_name)
{
	char line[MAX_INPUT_LENGTH];
	char *cmd_argv[MAX_INPUT_LENGTH];
	ssize_t byte_read;
	int script, exit_status = 0;

	script = open(file_name, O_RDONLY);
	if (script == -1)
	{
		perror("Error opening script file");
		return (-1);
	}

	while ((byte_read = read(script, line, sizeof(line))) > 0)
	{
		line[byte_read] = '\0';

		cmd_parse(line, cmd_argv);
		if (cmd_argv[0] != NULL)
		{
			exit_status = cmd_execute(cmd_argv);

			if (exit_status == -1)
			{
				perror("Command execution failed");
			}
		}
	}

	close(script);
	return (exit_status);
}

/**
 * main - The shell source code
 * @argc: The number of argv passed
 * @argv: The array of argv passed
 * Return: 0 success
 */
int main(int argc, char *argv[])
{
	const char *script_name;

	if (argc > 1)
	{
		script_name = argv[1];
		return (check_script(script_name));
	}
	else
	{
		is_interactive();
	}
	return (0);
}
