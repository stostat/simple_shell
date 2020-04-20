#include "shell.h"
/**
 * _cd - handle cd builtin
 * @data: struct data
 * Return: int on succes
*/
int _cd(data_t *data)
{
	char *swd;
	char *home = "~";

	swd = getcwd(NULL, 0);
	if (!swd)
		perror("getcwd"), exit(EXIT_FAILURE);
	if (data->args[1] == NULL || _strcmp2(data->args[1], home) == 0)
		chdir(_getenv(data, "HOME"));
	else if (chdir(data->args[1]) != 0)
		perror("mfs");
	else
		chdir(data->args[1]);
	free(swd);
	return (1);
}

/**
 * _help - handles help biltin
 * @data: struct data
 * Return: integer
*/
int _help(data_t *data)
{
	if (data->args[1] == NULL)
		get_help();
	else
		more_help(data);
	return (1);
}

/**
 * printwd - handle pwd builtin
 * @data: struct data
 * Return: int on succes
*/
int printwd(data_t *data)
{
	char *swd;

	(void)data;
	swd = getcwd(NULL, 0);
	write(STDOUT_FILENO, swd, _strlen(swd));
	write(STDOUT_FILENO, "\n", 1);
	free(swd);
	return (1);
}

/**
 * myexit - handle exit builtin
 * @data: struct data
 * Return: int on succes
*/
int myexit(data_t *data)
{
	int status;
	char *mess = "Illegal number: ";
	char *count = _itoa(data->count);

	if (data->args[1])
	{
		status = _atoi(data->args[1]);
		if (status <= 0)
		{
			write(STDERR_FILENO, data->name, _strlen(data->name));
			write(STDERR_FILENO, ": ", 2);
			write(STDERR_FILENO, count, _strlen(count));
			write(STDERR_FILENO, ": ", 2);
			write(STDERR_FILENO, data->args[0], _strlen(data->args[0]));
			write(STDERR_FILENO, ": ", 2);
			write(STDERR_FILENO, mess, _strlen(mess));
			write(STDERR_FILENO, data->args[1], _strlen(data->args[1]));
			write(STDERR_FILENO, "\n", 2);
			free(count);
			data->ext = 2;
			return (0);
		}
		else
		{
			data->ext = status;
			free(count);
			free_args(data);
			free_env(data);
			if (data->ext != 0)
				exit(data->ext);
		}
	}
	free(count);
	free_args(data);
	free_env(data);
	if (data->ext != 0)
		exit(data->ext);
	exit(0);
	return (0);
}
