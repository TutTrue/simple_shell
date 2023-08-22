#include "main.h"
/**
 */
char *_path(char **env)
{
	int path_idx = 0, path_len = 0;
	char *path;

	while (env[path_idx] != NULL)
	{
		if (strncmp(env[path_idx], "PATH", 4) == 0)
			break;
		path_idx++;
	}

	path_len = strlen(env[path_idx]);

	path = malloc(path_len - 4);
	if (!path)
		return NULL;

	strcpy(path, env[path_idx] + 5);
	return (path);
	
}

char **_array_path(char *path)
{
	int i = 0, no_del = 0;
	char **array_path, *token, *tmp;
	while (path[i])
	{
		if (path[i] == ':')
			no_del++;
		i++;
	}
	
	array_path = malloc(sizeof(char *) * (no_del + 2)); //==> 2

	i = 0;
	token = strtok(path, ":");
	while (token != NULL)
	{
		array_path[i++] = token;
		token = strtok(NULL, ":");
	}
	array_path[i] = NULL;
	return (array_path);
}
char **concat_command(char **array_path, char *command)
{
	int i = 0, total_len = 0;
	char **concated_array, *temp;
	while (array_path[i])
		i++;

	concated_array = malloc(sizeof(char *) * (i + 2));

	i = 0;
	while (array_path[i])
	{
		if (i == 0)
		{
			concated_array[0] = malloc(strlen(command) + 1);
			strcpy(concated_array[0], command);
		}
		total_len = strlen(command) + strlen(array_path[i]) + 2; /* /bin/ls */
		concated_array[i + 1] = malloc(total_len);
		temp = malloc(total_len);
		//strcpy(temp, "");
		strcpy(temp, array_path[i]);
		strcpy(concated_array[i + 1], strcat(strcat(temp, "/"), command));
		i++;
		free(temp);
	}
	concated_array[i + 1] = NULL;
	return (concated_array);
}
void free_2darr(char **array_path)
{
	int i = 0;
	while (array_path[i])
		free(array_path[i++]);
	free(array_path[i]);
	free(array_path);
}
/*int main(int ac, char **av, char **env)
{
	char *path = _path(env);
	char **array_path = _array_path(path);
	char **concated_array = concat_command(array_path, "ls");

	int i = 0;
	while (concated_array[i])
	{
		printf("%s\n", concated_array[i]);
	    i++;
	}
	free(array_path);
	free(path);
	free_2darr(concated_array);
}*/
