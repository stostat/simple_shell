#include "shell.h"

/**
 * _launch - function that executes the comand once it found in PATH
 * @data: struct data
 * Return: int on succes
*/
int _launch(data_t *data)
{
	pid_t pid;
	int status;
	char *func = NULL;
	int read = 0;

	func = exec_path(data);
	if (func)
	{
		pid = fork();
		if (pid == 0)
		{
			read = execve(func, data->args, data->env);
			if (read != -1)
				perror("mfs: perror 126 acces");
			else
			{
				if (errno == EACCES)
					_errora(data);
				free_env(data);
				free_args(data);
				free(func);
				exit(data->ext);
			}
		}
		if (pid == -1)
			perror("mfs");
		else
		{
			do {
			waitpid(pid, &status, WUNTRACED);
			} while (WIFEXITED(status) && WIFSIGNALED(status));
		}
	}
	else
	{
		_errorf(data);
	}
	free(func);
	return (data->status);
}
