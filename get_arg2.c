#include "header.h"
/**
 *get_stat - check stat and executes
 *
 *@argv: arguments given by main..
 * Return: 0 on succes, -1 if fails..
 */
int get_stat(char **argv)
{
	path_list *path = NULL, *aux;
	struct stat st;
	pid_t  child_p;
	int status;

	path = get_path(argv[0]); /* linked list with path + argv[0] */
	aux = path;
	while (path)
	{
		if (stat(argv[0], &st) == 0) /* in case of path as input */
		{
			break;
		}

		if (stat(aux->data, &st) == 0) /* in case of only the name of command */
		{
			free(argv[0]);
			argv[0] = _strdup(aux->data); /*aka*/
			break;
		}

		aux = aux->next;
		if (!aux)
		{
			free_path(path), free_argv(argv);
			perror("Error"); /* if the search fails */
			return (-1);
		}
	}

	child_p = fork();
	if (child_p == 0)
	{
		execve(argv[0], argv, NULL);
		kill(getpid(), SIGINT); /* if something goes wrong */
	}
	wait(&status);
	free_path(path), free_argv(argv);

	return (0);
}
