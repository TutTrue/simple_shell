#include "shell.h"              
#include "commands_separator.h"

void handle_env(char **env)
{
	int i;

	for (i = 0; env[i]; i++)
		printf("%s\n", env[i]);	
}
