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
	char *buff = NULL, *dup = NULL, *tok = NULL;
	char **arg = NULL;
	int cnt = 0;

	while (1)
	{
		arg = calloc(40, sizeof(char *));

		cnt = 0;

		if (isatty(STDIN_FILENO) == 1)
			printf("$ ");

		if (getline(&buff, &n, stdin) == -1)
		{
			break;
		}

		if (_strcmp(buff, "exit") == 10) /* hardcode? maybe you mean hardcore */
			break;

		dup = _strdup(buff);
		tok = strtok(dup, " \"\"\n\t");

		while (tok)
		{
			arg[cnt] = strdup(tok);
			tok = strtok(NULL, " \"\"\n\t");
			cnt++;
		}

		get_stat(arg);
		free(dup);
	}
	free(buff);
	free_argv(arg);

	return (0);
}
