#include "shell.h"

void execute_program(char *line, char **env)
{
	pid_t my_pid = fork();
	int statues;
	char **args;

	args = commands_array(line);
	
	if (my_pid == 0)
	{
		execve(args[0], args, env);
		free(args);
		perror("./shell");
		exit(1);
	}
	else 
	{
		wait(&statues);
		free(args);
		return;
	}
		
}

char **commands_array(char *line)
{
	char **args = NULL;
	char *delim = " ";
	char *token;
	int i, len = 0;

	
	for (i = 0; line[i] != '\0'; i++)
		if (line[i] != *delim)
			len++;

	len += 1;
	args = malloc(sizeof(char *) * len);

	if (!args)
		return (0);
	
	token = strtok(line, delim);
	i = 0;
	while (token != NULL)
	{
		args[i] = token;
		i++;
		token = strtok(NULL, delim);
	}
	
	char *str = args[i - 1];

	args[i] = NULL;
	return (args);
}
