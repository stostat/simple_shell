#include "shell.h"
/**
 * exec_path - executes command line when not builtin
 * @data: struct data
 * Return: pointer to string with command
*/
char *exec_path(data_t *data)
{
	list_t *aux;
	char *f, slash[120] = "/";
	int status = 1;
	struct stat buffer;

	status = stat(data->args[0], &buffer);
	if (status == 0)
		return (_strdup(data->args[0]));

	data->pathl = sep_path(data);
	if (data->pathl == NULL)
		return (NULL);
	aux = data->pathl;
	while (data->pathl != NULL)
	{
		f = malloc(_strlen(data->pathl->str) + _strlen(data->args[0]) + 256);
		if (!f)
			return (NULL);
		_strcpy(f, data->pathl->str);
		_strcat(f, slash);
		_strcat(f, data->args[0]);
		if (f == NULL)
			break;
		status = stat(f, &buffer);
		if (status == 0)
		{
			if (aux)
				free_PATH(aux);
			return (f);
		}
		data->pathl = data->pathl->next;
		free(f);
	}
	if (aux)
	{
		free_PATH(aux);
		aux = NULL;
	}

	return (NULL);
}
