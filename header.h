#ifndef header_h
#define header_h

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <signal.h>

extern char **environ;

/**
 *struct path_list_s - A list of paths
 *
 *@data: a string where goes path's
 *@next: next path node ptr.
 */
typedef struct path_list_s
{
	char *data;

	struct path_list_s *next;

} path_list;

char *_getenv(const char *name);
path_list *addPath_node(path_list **head, const char *data);
char *_strdup(const char *str);
char **get_arg(char *str);
path_list *get_path(void);
void free_path(path_list *head);
int _strlen(char *str);
char *str_concat(char *s1, char *s2);

#endif
