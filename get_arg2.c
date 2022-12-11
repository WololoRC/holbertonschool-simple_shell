#include "header.h"
/**
 *get_stat - check stat and executes
 *
 *@argv: arguments given by main..
 * Return: 0 on succes, -1 if fails..
 */
int get_stat(char **argv)
{
	path_list *path = NULL;
	struct stat st;
	pid_t  child_p;

	path = get_path(argv[0]); /* linked list with path + argv[0] */
	while (path)
	{
		if (stat(argv[0], &st) == 0) /* in case of path as input */
		{
			break;
		}

		if (stat(path->data, &st) == 0) /* in case of only the name of command */
		{
			argv[0] = path->data;
			break;
		}

		path = path->next;
		if (!path)
		{
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

	free_path(path);

	return (0);
}
