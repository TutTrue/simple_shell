#ifndef MAIN_H
#define MAIN_H
#define BUFSIZE 1024

#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include "commands_separator.h"







/*-------------Main functions---------*/
void mainloop(char **av, char **env);
ssize_t _getline(char **line, size_t *n, int fd);
char **commands_array(char *line);
void execute_program(char *line, char **env, int line_number);
/*-------------End ain f);unctions---------*/
/*-------------Helper functions---------*/
void handle_signal(int sig);
int just_spaces(char *command);
void handle_exit(char *line, int line_number, list_cmd *my_list);
/*-------------End Helper functions---------*/

/*-------------Path functions---------*/
 char *_path(char **env);
char **_array_path(char *path);
char **concat_command(char **array_path, char *command);
/*-------------End Path functions---------*/

/*-------------String functions---------*/
char *_strcat(char *dest, char *src);
char *_strdup(char *str);
char *_strcpy(char *dest, char *src);
int _strlen(char *str);
int _strncmp(char *s1, char *s2, int count);
int _strcmp(char *s1, char *s2);
int _atoi(char *str);
void strtrim(char *line);
/*-------------End String functions---------*/

/*-------------Free functions---------*/
void free_2darr(char **array_path);
void free_strarr(char **args);
void free_all(char **args, char *path, char **array_path,
              char **concated_command);
/*-------------End Free functions---------*/
#endif
