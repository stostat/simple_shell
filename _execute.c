#include "shell.h"
/**
 * find_command - searchs function from command ine
 * @data: struct data
 * Return: void
*/
void find_command(data_t *data)
{
	int is_built = 0;

	is_built = _execute(data);
	if (is_built == -1)
		_launch(data);
}

/**
 * _execute - executes buitin or searches for command
 * @data: struct data
 * Return: int on succes
*/
int _execute(data_t *data)
{
	int i;

	built_t funcs[] = {{"cd", _cd}, {"help", _help}, {"exit", myexit},
	 {"pwd", printwd}, {"env", _myenv2}, {NULL, NULL}};


	if (!data->args)
		return (1);
	for (i = 0; funcs[i].built; i++)
	{
		if ((_strcmp2(data->args[0], funcs[i].built)) == 0)
			return ((funcs[i].f)(data));
	}
	return (-1);
}
