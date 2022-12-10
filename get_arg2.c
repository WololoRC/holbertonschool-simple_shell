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

	path = get_path(argv[0]);

	while (path)
	{
		if (stat(argv[0], &st) == 0)
		{
			break;
		}

		if (stat(path->data, &st) == 0)
		{
			argv[0] = path->data;
			break;
		}

		path = path->next;
		if (!path)
		{
			perror("Error");
			return (-1);
		}
	}

	child_p = fork();

	if (child_p == 0)
	{
		execve(argv[0], argv, NULL);
		kill(getpid(), SIGINT);
	}

	free_path(path);

	return (0);
}
