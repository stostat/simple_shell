#include "shell.h"

/**
 * _launch - function that executes the comand once it found in PATH
 * @data: struct data
 * Return: int on succes
*/
int _launch(data_t *data)
{
	pid_t pid;
	int status = 0;
	char *func = NULL;

	func = exec_path(data);
	if (func)
	{
		pid = fork();
		if (pid == -1)
		{
			if (func)
				free(func);
			perror("mfs:");
		}
		if (pid == 0)
		{
			execve(func, data->args, data->env);
			if (errno == EACCES)
				_errora(data);
			free_all(data);
			free(func);
			exit(data->ext);
		}
		else
		{
			do {
			waitpid(pid, &status, WUNTRACED);
			} while (WIFEXITED(status) && WIFSIGNALED(status));
			data->ext = WEXITSTATUS(status);
		}
	}
	else
		_errorf(data);
	free(func);
	return (data->status);
}
