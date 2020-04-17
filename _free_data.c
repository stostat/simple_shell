#include "shell.h"
/**
 * _free - function gfrees data
 * @data: struct data
 * Return: int on succes
*/
void _free(data_t *data)
{
	free(data->args);
	free(data->buf);
}
/**
 * free_env - function gfrees data
 * @data: struct data
 * Return: int on succes
*/
void free_env(data_t *data)
{
	int index;

	if (data->env)
	{
		for (index = 0; data->env[index]; index++)
			free(data->env[index]);
		free(data->env);
		data->env = NULL;
	}
}
/**
 * free_args - function gfrees data
 * @data: struct data
 * Return: int on succes
*/
void free_args(data_t *data)
{
	int i;

	if (!data->args)
		return;
	for (i = 0; data->args[i]; i++)
		free(data->args[i]);
	free(data->args);
	data->args = NULL;
}
/**
 * free_all - function gfrees data
 * @data: struct data
 * Return: int on succes
*/
void free_all(data_t *data)
{
	if (data->buf)
		free(data->buf);
	free_env(data);
	free_args(data);
}
/**
 * free_array - function gfrees data
 * @arr: struct data
 * Return: int on succes
*/
void free_array(char **arr)
{
	int i;

	if (arr)
	{
		for (i = 0; arr[i]; i++)
			free(arr[i]);
	free(arr);
	arr = NULL;
	}
}
