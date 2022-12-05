#include "header.h"
char **get_arg(char *str)
{
	char **argv;
	int cnt = 0;
	path_list *path = NULL;

	path = get_path(); /* inicializa una linked list que contiene cada direccion de $PATH, 
				todavia no esta en uso */

	argv = malloc(sizeof(char) * _strlen(str));

	argv[0] = strtok(str, "\n \t");

	while (argv[cnt])
	{
		cnt++;
		argv[cnt] = strtok(NULL, "\n \t");
	}

	free_path(path);
	return (argv);
}
