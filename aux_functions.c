#include "header.h"
/**
 *_strlen - gives lenght of a string
 *
 *@str: string
 * Return: @cnt(lenght).
 */
int _strlen(char *str)
{
	int cnt = 0;

	while (str[cnt])
	{
		cnt++;
	}

	return (cnt);
}
/**
 **str_concat -Return concatenated strings allocated in a new space of memory
 *
 *@s1: string to concatenate
 *@s2: string to concateante
 * Return: pointer to str concatenated or NULL
 */
char *str_concat(char *s1, char *s2)
{
	int cnt, cnt2, cntCat, cntCat2;
	char *str_cat = NULL;

	cntCat2 = 0;

	if (!s1)
		s1 = "";

	if (!s2)
		s2 = "";

	cnt = _strlen(s1);
	cnt2 = _strlen(s2);

	if (cnt == 0 && cnt2 == 0)
	{
		cnt = 2;
		cnt2 = 2;
		s1 = "";
		s2 = "";
	}

	str_cat = malloc(sizeof(char) * (cnt + cnt2));

	if (!str_cat)
	{
		return (NULL);
	}
	for (cntCat = 0; s1[cntCat] != '\0'; cntCat++)
	{
		str_cat[cntCat] = s1[cntCat];
	}

	for (cntCat2 = 0; s2[cntCat2] != '\0'; cntCat2++, cntCat++)
	{
		str_cat[cntCat] = s2[cntCat2];
	}

	return (str_cat);
}
/**
 **_strdup -duplicates a string allocated in a new memory space
 *
 *@str: string to copy
 * Return: pointer or NULL
 */
#include <stdlib.h>
char *_strdup(const char *str)
{
	int cnt = 0, cnt1 = 0;
	char *str_dup = NULL;

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
/**
 *_strcmp -Compare two strings
 *
 *@s1: string
 *@s2: string
 *
 * Return: ret
 */
int _strcmp(char *s1, char *s2)
{
	while ((*s1 == *s2) && (*s2 != '\0') && (*s1 != '\0'))
	{
		s1++;
		s2++;
	}

	return (*s1 - *s2);
}
