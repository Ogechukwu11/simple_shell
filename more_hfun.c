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
/**
 * _setenv - Initialize a new environment variable,
 *             or modify an existing one
 * @info: Structure containing potential arguments. Used to maintain
 *        constant function prototype.
 * @var: the string env var property
 * @value: the string env var value
 * Return: Always 0
 */
int _setenv(info_t *info, char *var, char *value)
{
	char buf[MAX_ENTRY_SIZE];
	list_t *node;
	char *p;

	if (!var || !value)
		return (0);
	if (_len(var) + _len(value) + 2 > MAX_ENTRY_SIZE)
	{
		return (1);
	}
	_cpy(buf, var);
	_strcat(buf, "=");
	_strcat(buf, value);
	node = info->env;
	while (node)
	{
		p = starts_with(node->str, var);
		if (p && *p == '=')
		{
			_cpy(node->str, buf);
			info->env_changed = 1;
			return (0);
		}
		node = node->next;
	}
	if (info->env_size + 1 >= MAX_ENV_SIZE)
	{
		return (1);
	}
	add_node_end(&(info->env), buf, 0);
	info->env_size++;
	info->env_changed = 1;
	return (0);
}
/**
 * starts_with - Check if a string starts with a given prefix
 * @str: The string to check
 * @prefix: The prefix to check against
 * Return: Pointer to the start of prefix in str, or NULL if not found
 */
char *starts_with(const char *str, const char *prefix)
{
	while (*prefix)
	{
		if (*prefix != *str)
			return (NULL);
		prefix++;
		str++;
	}
	return ((char *)str);
}
/**
 * add_node_end - adds a node to the end of the list
 * @head: address of pointer to head node
 * @str: str field of node
 * @num: node index used by history
 *
 * Return: size of list
 */
list_t *add_node_end(list_t **head, const char *str, int num)
{
	list_t *new_node, *node;

	if (!head)
		return (NULL);

	node = *head;
	new_node = (list_t *)malloc(sizeof(list_t));
	if (!new_node)
		return (NULL);
	_memset((void *)new_node, 0, sizeof(list_t));
	new_node->num = num;
	if (str)
	{
		new_node->str = _sdup(str);
		if (!new_node->str)
		{
			free(new_node);
			return (NULL);
		}
	}
	if (node)
	{
		while (node->next)
			node = node->next;
		node->next = new_node;
	}
	else
		*head = new_node;
	return (new_node);
}
