#include "header.h"
/**
 * free_argv - free argv
 * @argv: char
 *
 * Return: always 0.
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
/**
 * alloc_argv - alloc argv
 * @argv: char.
 * Return: always 0.
 */
void alloc_argv(char **argv)
{
	int cnt = 0;

	while (cnt < 40)
	{
		argv[cnt] = malloc(sizeof(char) * 1040);
		cnt++;
	}
}
