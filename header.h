#ifndef header_h
#define header_h

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>
#include <sys/wait.h>
#include <unistd.h>
#include <signal.h>

extern char **environ;

/**
 *path_linked_list - A list of paths
 *
 */
typedef struct path_list_s
{
	char *data;

	struct path_list_s *next;

} path_list;

char *_getenv(const char *name);
path_list *addPath_node(path_list **head, const char *data);
void print_pathList(const path_list *head);
char *_strdup(const char *str);
char **get_arg(char *str);
path_list *get_path(void);
int _strcmp(char *s1, char *s2);
void free_path(path_list *head);
int _strlen(char *str);

#endif
