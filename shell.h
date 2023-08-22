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







void mainloop(char **av, char **env);
void handle_signal(int sig);
int just_spaces(char *command);
ssize_t _getline(char **line, size_t *n, int fd);
int handle_line(char *line, size_t buf_size, int fd);
char **commands_array(char *line);
void execute_program(char *line, char **env);
char **concat_command(char **array_path, char *command);
char **_array_path(char *path);
 char *_path(char **env);


/*-------------Helper functions---------*/
char *_strcat(char *dest, char *src);
char *_strdup(char *str);
char *_strcpy(char *dest, char *src);
int _strlen(char *str);
int _strncmp(char *s1, char *s2, int count);
int _strcmp(char *s1, char *s2);
int _atoi(char *str);
void free_strarr(char **args);
void free_2darr(char **array_path);
void strtrim(char *line);
#endif
