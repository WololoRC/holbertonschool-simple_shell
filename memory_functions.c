#include "header.h"
/**
 *free_argv - frees memory alocated nodes of an array
 *
 *@argv: array
 * Return: nothing.
 */
void free_argv(char **argv)
{
	int cnt = 0;

	while (argv[cnt])
	{
		free(argv[cnt]);
		cnt++;
	}

	free(argv);
}
