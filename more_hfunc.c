#include "test.h"
/**
 * _strcat - concatenates two strings
 * @to: the destination buffer
 * @from: the source buffer
 *
 * Return: pointer to destination buffer
 */
char *_strcat(char *to, const char *from)
{
	int destlen = _len(to);
	int c;

	for (c = 0; from[c] != '\0'; c++)
		to[destlen + c] = from[c];

	to[destlen + c] = '\0';
	return (to);
}

/**
 * _memset - fills memory with a constant byte
 * @s: the pointer to the memory area
 * @b: the byte to fill *s with
 * @n: the amount of bytes to be filled
 * Return: (s) a pointer to the memory area s
 */
char *_memset(char *s, char b, unsigned int n)
{
	unsigned int i;

	for (i = 0; i < n; i++)
		s[i] = b;
	return (s);
}
/**
 * initialize_info - Initializes the info structure
 * @info: Pointer to the info structure to be initialized
 *
 * This function initializes the fields of the info structure and allocates
 * any necessary memory.
 */
void initialize_info(info_t *info)
{
	info->env = NULL;
	info->env_size = 0;
	info->env_changed = 0;

	info->env = NULL;
}
/**
 * cleanup_info - Cleans up and deallocates
 * resources associated with info structure
 * @info: Pointer to the info structure to be cleaned up
 *
 * This function frees any allocated memory and performs necessary cleanup
 * for the info structure.
 */
void cleanup_info(info_t *info)
{
	while (info->env != NULL)
	{
		list_t *temp = info->env;

		info->env = info->env->next;
		free(temp->str);
		free(temp);
	}
	info->env_size = 0;
	info->env_changed = 0;
}
