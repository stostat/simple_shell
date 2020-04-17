#include "shell.h"

/**
 * _itoa - Converts an integer to a string
 * @number: the number to convert
 * Return: number as a string
 */
char *_itoa(int number)
{
	unsigned int tmp;
	int div = 1, i = 0;
	char *str;

	str = malloc(sizeof(char) * 11);
	if (str == NULL)
		return (NULL);
	if (number < 0)
	{
		str[i++] = '-';
		tmp = number * -1;
	}
	else
		tmp = number;

	while (tmp / div > 9)
		div *= 10;
	while (div != 0)
	{
		str[i] = (tmp / div) + '0';
		tmp %= div;
		div /= 10;
		i++;
	}
	str[i] = '\0';
	return (str);
}

/**
* _errorf - print error if command is not found
* @data: shell data
*/
void _errorf(data_t *data)
{
	char *count;

	data->ext = 127;
	count = _itoa(data->count);
	write(STDERR_FILENO, data->name, _strlen(data->name));
	write(STDERR_FILENO, ": ", 2);
	write(STDERR_FILENO, count, _strlen(count));
	write(STDERR_FILENO, ": ", 2);
	write(STDERR_FILENO, data->args[0], _strlen(data->args[0]));
	write(STDERR_FILENO, ": ", 2);
	write(STDERR_FILENO, "not found\n", 11);
	free(count);
}

/**
* _errora - print error if command can not be accessed
* @data: shell data
*/
void _errora(data_t *data)
{
	char *count;

	data->ext = 126;
	count = _itoa(data->count);
	write(STDERR_FILENO, data->name, _strlen(data->name));
	write(STDERR_FILENO, ": ", 2);
	write(STDERR_FILENO, count, _strlen(count));
	write(STDERR_FILENO, ": ", 2);
	write(STDERR_FILENO, data->args[0], _strlen(data->args[0]));
	write(STDERR_FILENO, ": ", 2);
	write(STDERR_FILENO, "Permission denied\n", 19);
	free(count);
}
