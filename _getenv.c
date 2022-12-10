#include "header.h"
/**
 *_getenv - get value from a enviroment variable
 *
 *@name: string with VAR name
 *
 * Return: on success a duplicate from the VAR value, NULL if fails.
 */
char *_getenv(const char *name)
{
	int cnt, cnt2;
	int status;

	for (cnt = 0; environ[cnt]; cnt++)
	{
		status = 1;
		for (cnt2 = 0; environ[cnt][cnt2] != '='; cnt2++)
		{
			if (name[cnt2] != environ[cnt][cnt2])
			{
				status = 0;
				break;
			}
		}

		if (status == 1)
			return (_strdup(&environ[cnt][cnt2 + 1]));
	}

	return (NULL);
}
/**
 *addPath_node - add a node ona path_list list
 *@str: string coming for main's getline
 *@head: ptr to head node
 *@data: data
 * Return: @new node on success, NULL if fails.
 */
path_list *addPath_node(path_list **head, const char *data, char *str)
{
	char **aux = NULL;
	path_list *new = NULL, *last = NULL;

	new = malloc(sizeof(path_list));
	if (!new)
		return (NULL);

	aux = malloc(sizeof(char *) * 8);

	aux[0] = _strdup(data);
	aux[1] = str_concat(aux[0], "/");
	aux[2] = str_concat(aux[1], str);

	new->data = _strdup(aux[2]);
	new->next = NULL;

	free_argv(aux);

	if (!*head)
	{
		*head = new;
		return (new);
	}

	else
	{
		last = *head;

		while (last->next != NULL)
		{
			last = last->next;
		}

		last->next = new;

		return (new);
	}
}
/**
 *get_path - initalizes a path_list list
 *
 *@str: string coming for main's getline
 * Return: @head ptr.
 */
path_list *get_path(char *str)
{
	char *path = NULL, **data = NULL;
	path_list *head = NULL;
	int cnt = 0, cnt2 = 0;

	path = _getenv("PATH");

	while (path[cnt2])
	{
		cnt2++;
	}

	data = malloc(sizeof(char *) * 40);

	data[cnt] = strtok(path, ":");

	while (data[cnt])
	{
		addPath_node(&head, data[cnt], str);
		cnt++;
		data[cnt] = strtok(NULL, ":");
	}

	free(data);
	free(path);

	return (head);
}
/**
 *free_path - free's a path_node list
 *
 *@head: @head ptr
 * Return: nothing.
 */
void free_path(path_list *head)
{
	path_list *crt_node = NULL;

	while (head)
	{
		crt_node = head;
		head = head->next;

		free(crt_node->data);
		free(crt_node);

	}
}
