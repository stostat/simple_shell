#include "shell.h"

/**
 * _strstr - locates a substring
 *
 * @haystack: pointer to the string
 * @needle:   pointer to the string to search in haystack
 *
 * Return:  a pointer to the beginning of the located substring,
 * or NULL if the substring is not found
 */

char *_strstr(char *haystack, char *needle)
{
	int runner;

	while (*haystack)
	{
		for (runner = 0; *(needle + runner); runner++)
			if (*(needle + runner) != *(haystack + runner))
				break;
		if (!*(needle + runner))
			return (haystack);
		haystack++;
	}
	return (NULL);
}

/**
 * _strcmp - compares two strings
 * @s1: string 1
 * @s2: string 2
 * @n: length of the strings.
 * Return: an integer less than, equal to, or greater than zero if s1 is found,
 * respectively to be less than, to match, or be greater than s2
 */

int _strcmp(char *s1, char *s2, size_t n)
{
	int cmp;
	size_t i = 0;

	while (*s1 && *s2)
	{
		i++, s1++, s2++;
		if (i == n || !(*s1))
			return (0);
	}
	cmp = *s1++ - *s2++;
	return (cmp);
}

/**
 * _strlen  -  returns the length of a string.
 * @s: given string
 *
 * Return: String length
 */
int _strlen(char *s)
{
	int length = 0;

	if (*s)
	{
		while (*(s + length))
			++length;
	}

	return (length);
}

/**
 * _strdup - allocates a new space in memory, which contains
 * a copy of the string given as a parameter.
 * @str: string to be copied
 *
 * Return: a pointer to a new string which is a duplicate of the string str
 */
char *_strdup(char *str)
{
	char *cpy;
	unsigned int size = 0;

	if (str)
	{
		while (str[size++])
			continue;

		cpy = malloc(size * sizeof(char));
		if (cpy)
		{
			while (size--)
				cpy[size] = str[size];
			return (cpy);
		}
	}
	return (NULL);
}

/**
 * _strcpy - copies the string pointed to by src,
 * including the terminating null byte (\0), to the buffer pointed to by dest
 *
 * @src:  source string array
 * @dest: destiny for src array
 *
 * Return: dest
 */

char *_strcpy(char *dest, char *src)
{
	int position;

	for (position = 0; src[position]; position++)
		dest[position] = src[position];
	dest[position] = '\0';
	return (dest);
}
