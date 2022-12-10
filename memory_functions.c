#include "header.h"
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
