#include "test.h"

/**
 * _getminenv - To get the value of an environment variable
 * @name: Name of the variable to get
 *
 * Return: A pointer to the value
 */
char *_getminenv(const char *name)
{
	char **env = environ;
	char *found;

	while (*env != NULL)
	{
		found = *env;
		if (str_cmp(found, name, _len(name)) == 0)
		{
			return (found + _len(name) + 1);
		}
		env++;
	}
	return (NULL);
}

/**
 * search_cmd - To search if the command is exec in PATH
 * @input: The array containing parsed input
 * Return: 0 success
 */
char *search_cmd(char *input)
{
	char *get_path, *total_path, *copy_path;
	char *token;
	size_t total_path_len;

	get_path = _getminenv("PATH");
	copy_path = _sdup(get_path);
	token = _strtok(copy_path, ":");

	while (token != NULL)
	{
		total_path_len = _len(token) + 1 + _len(input) + 1;

		total_path = (char *)malloc(total_path_len);
		if (total_path == NULL)
		{
			perror("Memory allocation failed");
			exit(EXIT_FAILURE);
		}

		_cpy(total_path, token);
		str_cat(total_path, "/");
		str_cat(total_path, input);
		if (access(total_path, X_OK) == 0)
		{
			free(copy_path);
			return (total_path);
		}

		free(total_path);
		token = _strtok(NULL, ":");
	}
	free(copy_path);
	return (NULL);
}

/**
 * execve_cmd - A function that acts as execve
 * @total_path: The full path
 * @argv: The array containing the total_path
 * Return: -1 failure
 */
int execve_cmd(char *total_path, char **argv)
{
	if (execve(total_path, argv, environ) == -1)
	{
		perror("Execve failed");
		exit(EXIT_FAILURE);
	}
	return (-1);
}

/**
 * cmd_execute - A function that executes commands
 * @argv: The array containing the arguments
 * Return: -1 on failure
 */
int cmd_execute(char **argv)
{
	pid_t child_pid;
	int status;
	char *total_path;
	int flag = 0;

	total_path = argv[0];

	if (access(total_path, X_OK) != 0)
	{
		total_path = search_cmd(argv[0]);
		flag = 1;
	}
	if (total_path == NULL)
	{
		perror("Command not found");
		return (-1);
	}

	child_pid = fork();
	if (child_pid == -1)
	{
		perror("Fork failed");
		return (-1);
	}

	if (child_pid == 0)
	{
		return (execve_cmd(total_path, argv));
	}
	else
	{
		wait(&status);
		if (WIFEXITED(status))
		{
			if (flag)
				free(total_path);
			return (WEXITSTATUS(status));
		}
		else
		{
			perror("Command did not exit normally");
			exit(2);
		}
	}
	return (0);
}
