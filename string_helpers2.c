#include "shell.h"

/**
 * _strncmp - compares two strings
 *
 * @s1: string 1
 * @s2: string 2
 * @n: length of the strings.
 * Return: an integer less than, equal to, or greater than zero if s1 is found,
 * respectively to be less than, to match, or be greater than s2
 */

int _strncmp(char *s1, char *s2, size_t n)
{
	size_t i = 0;

	while (*s1 && *s2 && i < n)
	{
		if (s1[i] > s2[i])
			return (s1[i] - s2[i]);
		if (s1[i] < s2[i])
			return (s1[i] - s2[i]);
		i++;
	}
	if (i == n)
		return (0);
	return (-1);
}

/**
 * _strcat -  appends the src string to the dest string, overwriting the
 * terminating null byte (\0) at the end of dest, and then adds a terminating
 * null byte
 *
 * @dest:  initial string
 * @src:   string to append to dest
 *
 * Return: a pointer to the resulting string dest
 */

char *_strcat(char *dest, char *src)
{
	char *runner = dest;

	while (*runner)
		runner++;
	while (*src)
		*runner++ = *src++;
	*runner = 0;

	return (dest);
}

/**
 * _strncat -  concatenates two strings.
 *
 * @dest:  initial string
 * @src:   string to append to dest
 * @n:     number of bytes to copy
 * Return: a pointer to the resulting string dest
 */
char *_strncat(char *dest, char *src, int n)
{
	char *runner = dest;

	while (*runner)
		runner++;
	while (*src && n--)
		*runner++ = *src++;
	*runner = 0;
	return (dest);
}

/**
 * _strcmp2 - compares two strings
 *
 * @s1: string 1
 * @s2: string 2
 *
 * Return: an integer less than, equal to, or greater than zero if s1 is found,
 * respectively to be less than, to match, or be greater than s2
 */

int _strcmp2(char *s1, char *s2)
{
	int cmp = 0;

	while (*s1 && *s2)
	{
		cmp = *s1++ - *s2++;
		if (cmp == 0)
			continue;
		else
			break;
	}

	return (cmp);
}
