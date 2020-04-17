#include "shell.h"

/**
* _getenv - finds a enviroment variable.
* @data: struct with the shell data.
* @name: variable to get.
*
* Return: a pointer to the variable.
*/
char *_getenv(__attribute__ ((unused)) data_t *data, char *name)
{
	int index, len;

	len = _strlen(name);

	for (index = 0; environ[index]; index++)
	{
		if (_strncmp(name, environ[index], len) == 0)
			return (environ[index]);
	}

	return (NULL);
}

/**
 * free_PATH - frees PATH variable
 * @head: struct data
 * Return: void
*/
void free_PATH(list_t *head)
{
	list_t *tmp;

	while (head != NULL)
	{
		tmp = head->next;
		/* free(head->len); */
		free(head->str);
		free(head);
		head = tmp;
	}
}
/**
* _myenv2 - prints the current enviroment
* @data: struct with the shell data
* Return: 0 on success otherwise -1
*/

int _myenv2(__attribute__ ((unused)) data_t *data)
{
	int i = 0;
	char nl = '\n';

	if (!environ)
		return (-1);

	while (environ[i])
	{
		write(STDOUT_FILENO, environ[i], _strlen(environ[i]));
		write(STDOUT_FILENO, &nl, 1);
		i++;
	}
	return (0);
}
