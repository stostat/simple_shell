#include "shell.h"
/**
 * get_help - prints help according to call
 * Return: int
*/
int get_help(void)
{
	char simplehelp[] = "These shell commands are defined internally.\n"
	"Type 'help' to see this list.\npwd [-LP]\ncd [dir]\nenv\nexit [n]\n"
	"help [-dms] [pattern ...]\n";

	write(STDOUT_FILENO, simplehelp, _strlen(simplehelp));
	return (1);
}
/**
* more_help - prints help
* @data: struct
* Return: int on succes
*/
int more_help(data_t *data)
{
	int i, j = -1;
	char comp[4][5] = {"cd", "pwd", "exit", "env"};
	char pcd[] = "cd: cd [dir]\nChange the shell working directory.\n"
	"Change the current directory to specified.\nExit Status:\n"
	"Returns 0 if the directory is changed, non-zero otherwise.\n";
	char ppwd[] = "pwd: pwd\nPrint the name of the current working directory.\n"
	"Exit Status:\nReturns 0 unless an invalid option is given or the current directory\n"
	"cannot be read.\n";
char pexit[] = "exit: exit [n]\nExit the shell.\n"
"Exits the shell with a status of N.  If N is omitted, the exit status\n"
"is that of the last command executed.\n";
char penv[] = "env: env [OPTION]\nPrints the enviroment variables\n"
"Without argument prints all the variables.\n";

	for (i = 0; comp[i]; i++)
	{
		j = _strcmp2(data->args[1], comp[i]);
		if (j == 0 || j == -1)
			break;
	}
	switch (i)
	{
		case 0:
		write(STDOUT_FILENO, pcd, _strlen(pcd));
		break;
		case 1:
		write(STDOUT_FILENO, ppwd, _strlen(ppwd));
		break;
		case 2:
		write(STDOUT_FILENO, pexit, _strlen(pexit));
		break;
		case 3:
		write(STDOUT_FILENO, penv, _strlen(penv));
		break;
		default:
		write(STDOUT_FILENO, "help: no help topics match\n", 27);
		break;
	}
	return (0);

}
