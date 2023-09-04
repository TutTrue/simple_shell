#include "shell.h"              
#include "commands_separator.h"

void handle_chdir(char *line, int line_number, list_cmd *sep_cmds)
{
	char *token;

	token = strtok(line, " ");
	token = strtok(NULL, " ");

	if (!token)
		return;

	if (chdir(token) != 0)
	{
		fprintf(stderr,"./hsh: %d: cd: can't cd to %s\n", line_number, token);
		if (!isatty(0))
		{
			free(line);
			free_list(sep_cmds);
			exit(2);
		}
	}
}
