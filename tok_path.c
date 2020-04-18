#include "shell.h"

/**
 * sep_path - takes PATH variable and separates folders
 * @data: data structure
 * Return: a pointer to an array of strings (words)
 */
list_t *sep_path(data_t *data)
{
	list_t *path = NULL;
	char *sep = ":";
	char *path_block = NULL;

	path_block = _getenv(data, "PATH");
	if (path_block != NULL)
	{
		path = parse_path(path_block, _strlen(path_block), sep);
	}
	return (path);
}

/**
 * parse_path - creates a linked list wirh each folder on path
 * @line: array with PATH
 * @l: data int type with PATH lenght
 * @sep: array with separators info
 * Return: a pointer to alinked list
 */
list_t *parse_path(char *line, ssize_t l, char *sep)
{
	ssize_t i = 0;
	char **aux = NULL;
	list_t *head = NULL;

	if (line == NULL || l <= 0)
		return (NULL);
	aux = _strtok(line, sep);
	for (i = 0; aux[i]; i++)
	{
		if (add_list(&head, aux[i]) == NULL)
		{
			free_list(head);
			free_array(aux);
			return (NULL);
		}
	}
	free_array(aux);
	return (head);
}

/**
 * add_list - adds a node each time a folder is parsed
 * @head: double pointer to head of linked list
 * @str: array of strings with the folder name
 * Return: a pointer to the sata structure
 */
list_t *add_list(list_t **head, char *str)
{
	int count = 0;
	list_t *node = NULL, *aux = *head;

	if (head == NULL)
		return (NULL);
	node = malloc(sizeof(list_t));
	if (node == NULL)
		return (NULL);
	while (str[count] != '\0')
		count++;
	node->str = _strdup(str);
	node->len = count;
	node->next = NULL;
	if (*head == NULL)
	{
		*head = node;
		return (node);
	}
	while (aux->next != NULL)
		aux = aux->next;
	aux->next = node;
	return (*head);
}

/**
 * free_list - releases memory
 * @head: pointer to first node of the linked list
 * Return: nothing
 */
void free_list(list_t *head)
{
	list_t *tmp;

	while (head != NULL)
	{
		tmp = head;
		head = head->next;
		free(tmp);
	}
}
