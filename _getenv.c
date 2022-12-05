#include "header.h" 
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

		if(status == 1)
			return (_strdup(&environ[cnt][cnt2 + 1]));
	}

	return (NULL);
}
path_list *addPath_node(path_list **head, const char *data)
{
	path_list *new, *last;
	char *aux = NULL;
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
path_list *get_path(void)
{
	char *path, **aux;
	path_list *head = NULL;
	int cnt = 0, cnt2 = 0;

	path = _getenv("PATH");

	while (path[cnt2])
	{
		cnt2++;
	}

	aux = malloc(sizeof(path) * cnt2);

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
