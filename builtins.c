#include "shell.h"
/**
 * _cd - handle cd builtin
 * @data: struct data
 * Return: int on succes
*/
int _cd(data_t *data)
{
	char *swd;

	swd = getcwd(NULL, 0);
	if (!swd)
		perror("getcwd"), exit(EXIT_FAILURE);
	if (data->args[1] == NULL)
		chdir(_getenv(data, "HOME") + 5);
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
	free_args(data);
	free_env(data);
	if (data->ext == 127)
		exit(data->ext);
	exit(0);
}
