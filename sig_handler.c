#include "shell.h"

/**
 * sig_handler - exits program on signal
 * @sig_num: signal number
 * return: exits on succes
 */
void sig_handler(int sig_num)
{
	(void)sig_num;
	signal(SIGINT, sig_handler);
	write(STDIN_FILENO, "\nಠ╭╮ಠ > ", 9);
}
