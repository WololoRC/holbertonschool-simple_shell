#include "header.h"
char *_strdup(const char *str)
{
	int cnt, cnt1;
	char *str_dup = NULL;

	cnt = 0;
	cnt1 = 0;

	if (!str)
	{
		return (NULL);
	}

	while (str[cnt])
	{
		cnt++;
	}

	str_dup = malloc(sizeof(char) * cnt + 1);
	if (!str_dup)
	{
		return (NULL);
	}

	while (str[cnt1])
	{
		str_dup[cnt1] = str[cnt1];
		cnt1++;
	}

	return (str_dup);
}
