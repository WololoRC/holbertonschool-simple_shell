#include "header.h"
/**
 * main - Entry point
 *
 *
 * Return: Always 0.
 */
int main(void)
{
	size_t n = 0;
	char *buff = NULL;
	char **arg = NULL;
	int cnt = 0;
	int status;

	arg = malloc(sizeof(char *) * 40);
	while (1)
	{
		cnt = 0;
		if (isatty(STDIN_FILENO) == 1)
			printf("$ ");
		if (getline(&buff, &n, stdin) == -1)
		{
			printf("\n");
			break;
		}
		if (_strcmp(buff, "exit") == 10)
			break;
		arg[cnt] = strtok(buff, " \n\"\"\t");
		while (arg[cnt])
		{
			cnt++;
			arg[cnt] = strtok(NULL, " \n\"\"\t");
		}
		arg = realloc(arg, sizeof(char *) * 40);
		get_stat(arg);
		wait(&status);
	}
	free(arg);
	free(buff);
	return (0);
}
