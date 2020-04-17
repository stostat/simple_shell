#include "shell.h"
/**
 * _dupenv - duplicates enviroment variables
 * Return: double pointer to start of env
*/
char **_dupenv(void)
{
	char **dup_env = NULL;
	size_t size = 0;
	int index;

	while (environ[size])
		size++;

	dup_env = malloc(sizeof(char *) * (size + 1));
	if (!dup_env)
		return (NULL);

	for (index = 0; environ[index]; index++)
	{
		dup_env[index] = _strdup(environ[index]);
		if (!dup_env[index])
		{
			for (index--; index >= 0; index--)
				free(dup_env[index]);
			free(dup_env);
			return (NULL);
		}
	}
	dup_env[size] = NULL;

	return	(dup_env);
}
