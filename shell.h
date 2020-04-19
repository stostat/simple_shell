#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <dirent.h>
#include <signal.h>
#include <errno.h>
#include <fcntl.h>


extern char **environ;
/**
 * struct list_s - struct for PATH
 * @len: lenght
 * @str: char with str
 * @next: node
 */
typedef struct list_s
{
	unsigned int len;
	char *str;
	struct list_s *next;
} list_t;

/**
 * struct data - contains most variables passed through shell
 * @name: program name
 * @buf: buffer containing the input
 * @line: read line return
 * @args:  tokenized input line, first element is the actual command
 * @status: status of function
 * @count: counter of reads for error message
 * @ext: exit status code (126, 127 error not found, 129, interrump, 0,)
 * exit status code (126, 127 error not found, 130, interrump, 0,)
 * @path: the command path
 * @pathl: linked list with the dirs of the PATH
 * @env: linked list copy from environ
 */
typedef struct data
{
	char *name;	/* program name */
	char *buf;	/* buffer containing the input */
	char *line;	/* read line return*/
	char **args;/* tokenized input line, first element is the actual command*/
	int status;	/* status of function*/
	int count; /* counter of reads for error message */
	int ext; /* exit status code (126, 127 error not found, 129, interrump, 0,)
* exit status code (126, 127 error not found, 130, interrump, 0,)
*/
	char *path;	/* the command path */
	char **env;/* linked list copy from environ */
	list_t *pathl;
} data_t;

/**
 * struct built_in - struct for builtin functions
 * @built: str to builtin match
 * @f: pointer to function
 */
typedef struct built_in
{
	char *built;
	int (*f)(data_t *data);
} built_t;




void sig_handler(int sig_num);
void init_data(data_t *data, char **av);

char **_dupenv(void);
void free_env(data_t *data);
char *_getenv(data_t *data, char *str);

int _cd(data_t *data);
int _help(data_t *data);
int myexit(data_t *data);
int printwd(data_t *data);
int get_help(void);
int more_help(data_t *data);

int _execute(data_t *data);

char *_strdup(char *str);
int _strlen(char *s);
char *_strcpy(char *dest, char *src);
char **strtow(data_t *data, char *delimiter);
char **_strtok(char *str, char *delimiter);
int _strncmp(char *s1, char *s2, size_t n);
int _strcmp2(char *s1, char *s2);
char *_strcat(char *dest, char *src);
char *_strncat(char *dest, char *src, int n);
int _delimiters(char c, char *delimiter);
int _atoi(char *s);
char *_itoa(int number);
size_t listint_len(const list_t *h);

void free_args(data_t *data);
void _free(data_t *data);
void free_all(data_t *data);
void free_list(list_t *head);
void free_PATH(list_t *head);
void free_array(char **arr);

int loop_prompt(data_t *data);
ssize_t handle_input(data_t *data);
ssize_t read_line(data_t *data);
char **parse_line(data_t *data);
int _execute(data_t *data);
int execute(data_t *data);
void find_command(data_t *data);
char *find_path(data_t *data);
int _launch(data_t *data);
list_t *parse_path(char *line, ssize_t len, char *sep);
list_t *sep_path(data_t *data);
list_t *add_list(list_t **head, char *str);
char *exec_path(data_t *data);
void find_command(data_t *data);

void _errorf(data_t *data);
void _errora(data_t *data);
int _myenv2(data_t *data);

#endif /* SHELL_H */
