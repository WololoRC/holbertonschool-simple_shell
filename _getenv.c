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
 *
 *@head: ptr to head node
 *@data: data
 * Return: @new node on success, NULL if fails.
 */
path_list *addPath_node(path_list **head, const char *data)
{
	path_list *new, *last;

	new = malloc(sizeof(path_list));
	if (!new)
		return (NULL);

	new->data = _strdup(data);
	new->next = NULL;

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
 *
 * Return: @head ptr.
 */
path_list *get_path(void)
{
	char *path, **aux = NULL;
	path_list *head = NULL;
	int cnt = 0, cnt2 = 0;

	path = _getenv("PATH");

	while (path[cnt2])
	{
		cnt2++;
	}

	aux = malloc(sizeof(path) * (cnt2));

	aux[cnt] = strtok(path, ":");

	while (aux[cnt])
	{
		addPath_node(&head, aux[cnt]);
		cnt++;
		aux[cnt] = strtok(NULL, ":");
	}

	free(aux);
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
