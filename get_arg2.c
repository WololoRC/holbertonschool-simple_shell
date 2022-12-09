#include "header.h"
/**
 *get_stat - turns the stirng passed by main in arguments for execve
 *@argv: char.
 *
 * Return: @argv(arguments vector).
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
			perror("Error");
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
