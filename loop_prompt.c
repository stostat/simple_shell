 #include "shell.h"

/**
 * loop_prompt - loop for prompt
 * @data: sata structure
 * Return: 0 on succes
*/
int loop_prompt(data_t *data)
{
	ssize_t read;
	char *prompt = "$ ";

	signal(SIGINT, sig_handler);
	do {
		if (isatty(STDIN_FILENO))
			write(STDIN_FILENO, prompt, 2);
		read = handle_input(data);
		if (read == -1)
		{
			free_all(data);
			free_list(data->pathl);
		}
			find_command(data);
			free_args(data);
		} while (1);
	return (data->status);
}
