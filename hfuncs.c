#include "test.h"

/**
 * str_cmp - To compare two strings up to a specified length.
 * @seq1: The first sequence
 * @seq2: The second sequence
 * @len: The maximum number of characters to compare
 *
 * Return: 0 if the sequences are equal, otherwise a non-zero value.
 */
int str_cmp(const char *seq1, const char *seq2, int len)
{
	int c;

	for (c = 0; c < len; c++)
	{
		if (seq1[c] != seq2[c])
			return (seq1[c] - seq2[c]);
		if (seq1[c] == '\0')
			return (0);
	}
	if (c == len)
		return (0);

	return (seq1[c] ? 1 : -1);
}

/**
 * _cpy - A function that copies a string
 * @destination: The destination
 * @source: The source of the string
 * Return: A pointer to the destination string
 */
char *_cpy(char *destination, const char *source)
{
	char *dest_start;

	if (source != NULL && destination != NULL)
	{
		dest_start = destination;

		while (*source != '\0')
		{
			*destination = *source;
			destination++;
			source++;
		}

		*destination = '\0';

		return (dest_start);
	}

	return (NULL);
}

/**
 * _sdup - A function to duplicate a string
 * @source: The string obtained
 * Return: The duplicated string
 */
char *_sdup(const char *source)
{
	int c1, c2;
	char *dp;

	if (source == NULL)
		return (NULL);

	c1 = 0;
	while (source[c1] != '\0')
	{
		c1++;
	}

	dp = (char *)malloc((c1 + 1) * sizeof(char));
	if (dp == NULL)
	{
		return (NULL);
	}

	c2 = 0;
	while (c2 < c1)
	{
		dp[c2] = source[c2];
		c2++;
	}

	dp[c2] = '\0';
	return (dp);
}

/**
 * str_chr - To find a character in a string
 * @sequence: The string
 * @ch: The character to locate
 * Return: A pointer to the character in the string
 */
const char *str_chr(const char *sequence, char ch)
{
	int it = 0;

	while (sequence[it] != '\0')
	{
		if (sequence[it] == ch)
			return (&sequence[it]);
		it++;
	}

	return (NULL);
}

/**
 * str_cat - a function that concatenates two strings
 * @to: string1
 * @from: string2
 * Return: a pointer to the resulting string destination
 */
char *str_cat(char *to, char *from)
{
	int destlen = 0;
	int srclen = 0;
	int c;

	for (c = 0; to[c] != '\0'; c++)
		destlen++;
	for (c = 0; from[c] != '\0'; c++)
		srclen++;

	for (c = 0; c <= srclen; c++)
		to[destlen + c] = from[c];
	return (to);
}
