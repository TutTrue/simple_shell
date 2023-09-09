#include "shell.h"              
#include "commands_separator.h"

void handle_chdir(char *line, int line_number, list_cmd *sep_cmds)
{
	char *token;
	static char old_pwd[BUFSIZE];

	token = strtok(line, " ");
	token = strtok(NULL, " ");

	if (!token)
	{
		if (getenv("HOME"))
			chdir(getenv("HOME"));
		return;
	}

	if (_strncmp(token, "-", 1) == 0)
	{
		_strcpy(token, old_pwd);
		printf("%s\n", token);
	}

	getcwd(old_pwd, sizeof(old_pwd));
	if (chdir(token) != 0)
	{
		fprintf(stderr,"./hsh: %d: cd: can't cd to %s\n", line_number, token);
		if (!isatty(0))
		{
			printf("%s\n", old_pwd);
			free(line);
			free_list(sep_cmds);
			exit(0);
		}
	}
}
