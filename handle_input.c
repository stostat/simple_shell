#include "shell.h"


/**
 * handle_input - calls functions to get and parse command line
 * @data: struct data
 * Return: unsigned int size input
*/
ssize_t handle_input(data_t *data)
{
	ssize_t line;

	line = read_line(data);
		if (line == -1)
			return (-1);
	parse_line(data);
		if (!data->args)
		{
			free_args(data);
			free_env(data);
			free(data->buf);
		}
	return (line);
}

/**
 * read_line - calls functions to get and parse command line
 * @data: struct data
 * Return: unsigned int size input
*/
ssize_t read_line(data_t *data)
{
	size_t len = 0;
	ssize_t read = 0;

	data->buf = NULL;

	read = getline(&data->buf, &len, stdin);
	if (read == -1)
	{
		write(STDIN_FILENO, "\n", 1);
		free_all(data);
		exit(0);
	}
	if (read > 0)
	{
		data->buf[read - 1] = '\0';
		read--;
		data->count++;
	}
	return (read);
}

/**
 * parse_line - calls functions to get and parse command line
 * @data: struct data
 * Return: double pointer to each token
*/
char **parse_line(data_t *data)
{
	strtow(data, " \t");
	free(data->buf);
	data->buf = NULL;
	if (!data->args)
	{
		free_all(data);
		return (NULL);
	}
	else
		return (data->args);
}
