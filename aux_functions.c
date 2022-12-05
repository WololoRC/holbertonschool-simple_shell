#include "header.h"
int _strlen(char *str)
{
	int cnt = 0;

	while (str[cnt])
	{
		cnt++;
	}

	return (cnt);
}
