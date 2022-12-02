#include "main.h"
char *_getenv(const char *name)
{
	char *w = NULL;
	int i = 0, j = 0;

	for (; environ[i] != NULL; i++)/*loop to travel the environ array*/
	{
		w = environ[i];
		while (name[j] != '\0' && name[j] == w[j])
			j++;
		if (name[j] == '\0' && w[j] == '/')
			return (w);
	}
	return (NULL);
}
