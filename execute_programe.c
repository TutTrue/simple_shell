#include "shell.h"

void execute_program(char *line, char **env, int line_number)
{
	int i = 0;
	int statues;
	char **array_path, **args, **concated_command;
	char *path;

	path = _path(env);
	array_path = _array_path(path);
	args = commands_array(line);
	concated_command = concat_command(array_path, args[0]);

	while (concated_command[i])
	{
		if (access(concated_command[i], X_OK) == 0)
		{
			pid_t my_pid = fork();
			if (my_pid == 0)
			{
				execve(concated_command[i], args, env);
				free_all(args, path, array_path, concated_command);
				exit(127);
			}
			else 
			{
				wait(&statues);
				free_all(args, path, array_path, concated_command);
				return;
			}
		}
		i++;
	}
	fprintf(stderr, "./hsh: %d: %s: not found\n", line_number, args[0]);
	free_all(args, path, array_path, concated_command);
	if (!isatty(0))
	{
		free(line);
		exit(127);
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

	args[i] = NULL;
	return (args);
}
void free_all(char **args, char *path, char **array_path, char **concated_command)
{
	if (args)
		free(args);
	if (path)
		free(path);
	if (array_path)
		free(array_path);
	free_2darr(concated_command);
}
