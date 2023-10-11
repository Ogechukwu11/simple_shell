#include "test.h"

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
 * exec_command - Execute the given command
 * @total_path: The full path to the command
 * @argv: The array containing the command and its arguments
 * @flag: Flag to determine if total_path needs to be freed
 * Return: The exit status of the executed command or -1 on failure
 */
int exec_command(char *total_path, char **argv, int flag)
{
	int exec_result, status;
	pid_t child_pid;

	child_pid = fork();
	if (child_pid == -1)
	{
		perror("Fork failed");
		if (flag)
			free(total_path);
		return (-1);
	}
	if (child_pid == 0)
	{
		exec_result = execve_cmd(total_path, argv);
		if (flag)
			free(total_path);
		exit(exec_result);
	}
	else
	{
		if (wait(&status) == -1)
		{
			perror("Wait failed");
			if (flag)
				free(total_path);
			return (-1);
		}
		return (status);
	}
}

/**
 * handle_execute_error - Handle errors during command execution
 * @flag: Flag to determine if total_path needs to be freed
 * @total_path: The full path to the command
 * @status: The status of the executed command
 */
void handle_execute_error(int flag, char *total_path, int status)
{
	if (flag)
		free(total_path);
	if (WIFEXITED(status) && WEXITSTATUS(status) != 0)
	{
		exit(2);
	}
	else if (!WIFEXITED(status))
	{
		perror("Command did not exit normally");
		exit(2);
	}
}

/**
 * cmd_execute - A function that executes commands
 * @argv: The array containing the arguments
 * Return: -1 on failure, else the exit status of the executed command
 */
int cmd_execute(char **argv)
{
	char *total_path, *searched_path;
	int status, flag = 0;

	total_path = argv[0];

	if (access(total_path, X_OK) != 0)
	{
		searched_path = search_cmd(argv[0]);
		if (searched_path != NULL)
		{
			total_path = searched_path;
			flag = 1;
		}
		else
		{
			perror("Command not found");
			return (-1);
		}
	}
	status = exec_command(total_path, argv, flag);
	handle_execute_error(flag, total_path, status);

	return (WEXITSTATUS(status));
}
