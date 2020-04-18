#include "shell.h"

/**
 * init_data - initializes variables
 * @data: struct data
 * @av: argument vector
 * Return: 0 on succes
*/
void init_data(data_t *data, char **av)
{

	data->name = av[0];
	data->ext = 0;
	data->status = 0;
	if (*environ)
		data->env = _dupenv();
	if (!data->env)
		*data->env = getcwd(NULL, 0);
}
