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
path_list *addPath_node(path_list **head, const char *data, char *str);
char *_strdup(const char *str);
int get_stat(char **str);
path_list *get_path(char *str);
void free_path(path_list *head);
int _strlen(char *str);
char *str_concat(char *s1, char *s2);
int _strcmp(char *s1, char *s2);
void free_argv(char **argv);
void alloc_argv(char **argv);
char **get_arg(char **argv, char *args);
char *_strcat(char *s1, char *s2);

#endif
