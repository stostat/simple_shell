#include "shell.h"

/**
 * main - launches all functions
 * @ac: arguments count
 * @av: arguments vector
 * Return: 0 on succes
*/
int main(__attribute__ ((unused)) int ac, char **av)
{
	data_t data[] = {{NULL, NULL, NULL, NULL, 0, 0, 0, NULL, NULL, NULL}};

	init_data(data, av);
	loop_prompt(data);
	free_args(data);
	free_env(data);

	return (0);
}
