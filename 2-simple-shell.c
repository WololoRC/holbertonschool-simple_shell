#include "header.h"
/**
 * main - Entry point
 *
 *
 * Return: Always 0.
 */
int main(void)
{
	size_t n = 10;
	char *buff = NULL;
	char **arg = NULL;
	int ch = 0;
	pid_t child_p;
	int status;

	while (ch != -1)
	{
		printf("$ ");

		buff = malloc(sizeof(char) * n);

		ch = getline(&buff, &n, stdin); /* @ch: checks getline return for EOF */

		arg = get_arg(buff);

		child_p = fork();

		if (child_p == 0)
		{
			execve(arg[0], arg, NULL);
			free(buff);
			free(arg);
			kill(getpid(), SIGINT);
		}

		free(buff);
		free(arg);
		wait(&status);
	}

	return (0);
}
