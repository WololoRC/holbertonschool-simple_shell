#include "header.h"
/**
 *get_arg - turns the stirng passed by main in arguments for execve
 *
 *@str: string given by main.
 * Return: @argv(arguments vector).
 */
char **get_arg(char *str)
{
	char **argv, *str_aux = NULL;
	int cnt = 0;
	path_list *path = NULL;
	struct stat st;

	path = get_path();

	argv = malloc(sizeof(char) * _strlen(str));

	while (path)
	{
		str_aux = str_concat(str_aux, str);

		argv[0] = strtok(_strdup(str_aux), "\n \t\"\"");

		if (stat(argv[0], &st) == 0)
		{
			argv = realloc(argv, (_strlen(str) + _strlen(str_aux)));
			break;
		}

		str_aux = str_concat(_strdup(path->data), "/");

		path = path->next;
	}

	while (argv[cnt])
	{
		cnt++;
		argv[cnt] = strtok(NULL, "\n \t\"\"");
	}

	free(str_aux);
	free_path(path);
	return (argv);
}
