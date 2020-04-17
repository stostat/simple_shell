#include "shell.h"
/**
 * _delimiters - finds characters in the command line to break args
 *
 * @c: character to be compared
 * @delimiter: array of characters to be compared
 * Return: on succes 1, else 0
 */
int _delimiters(char c, char *delimiter)
{
	for (; *delimiter;)
	{
		if (*delimiter++ == c)
			return (1);
	}
	return (0);
}
/**
 * count_letters - counts the number of letters of a word
 * @str: string.
 * @delimiter: string containing characters that indicate limits
 * Return: number of letters of a word
 */
int count_letters(char *str, char *delimiter)
{
	int index = 0, letters = 0;

	while (str[index] && !_delimiters(str[index], delimiter))
	{
		letters++;
		index++;
	}

	return (letters);
}

/**
 * count_words - Counts the number of words in a given string
 * @str: given string
 * @delimiter: string containing characters that indicate limits
 * Return: number of words in str.
 */
int count_words(char *str, char *delimiter)
{
	int index, words = 0, length = 0;

	for (index = 0; str[index]; index++)
		length++;

	for (index = 0; index < length; index++)
	{
		if (!_delimiters(str[index], delimiter) &&
			(_delimiters(str[index + 1], delimiter) || !str[index + 1]))
		{
			words++;
			index += count_letters(str + index, delimiter);
		}
	}

	return (words);
}

/**
 * strtow - splits a string into words
 * @data: pointer to data structure
 * @delimiter: string containing characters that indicate limits
 * Return: a pointer to an array of strings (words)
 */
char **strtow(data_t *data, char *delimiter)
{
	char *s = NULL;
	int index = 0, words, w, letters, l;

	 s = data->buf;

	if (s == NULL || s[0] == 0)
		return (NULL);

	words = count_words(s, delimiter);
	if (!words)
		return (NULL);

	data->args = malloc(sizeof(char *) * (words + 1));
	if (data->args == NULL)
		return (NULL);

	for (w = 0; w < words; w++)
	{
		while (_delimiters(s[index], delimiter))
			index++;

		letters = count_letters((s + index), delimiter);

		data->args[w] = malloc((letters + 1) * sizeof(char));
		if (data->args[w] == NULL)
		{
			while (w--)
				free(data->args[w]);
			free(data->args);
			return (NULL);
		}

		for (l = 0; l < letters; l++)
			data->args[w][l] = s[index++];

		data->args[w][l] = 0;
	}
	data->args[w] = NULL;
	return (NULL);
}

/**
 * _strtok - splits a string into words
 * @str: given string
 * @delimiter: array of strings that containt the specific delimiter
 * Return: a pointer to an array of strings (words)
 * NULL if str == NULL or str == ""
 */
char **_strtok(char *str, char *delimiter)
{
	char *strs = NULL, **new = NULL;
	int index = 0, words, w, letters, l;

	 strs = str;

	if (strs == NULL || str[0] == 0)
		return (NULL);

	words = count_words(strs, delimiter);
	if (!words)
		return (NULL);

	new = malloc(sizeof(char *) * (words + 1));
	if (new == NULL)
		return (NULL);

	for (w = 0; w < words; w++)
	{
		while (_delimiters(strs[index], delimiter))
			index++;

		letters = count_letters((strs + index), delimiter);

		new[w] = malloc((letters + 1) * sizeof(char));
		if (new[w] == NULL)
		{
			while (w--)
				free(new[w]);
			free(new);
			return (NULL);
		}

		for (l = 0; l < letters; l++)
			new[w][l] = strs[index++];

		new[w][l] = 0;
	}
	new[w] = NULL;
	return (new);
}
