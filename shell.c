#include "shell.h"

int main(int ar, char **av, char **env)
{
	(void)ar;
	signal(SIGINT, handle_signal);
	mainloop(av, env);
	return (0);
}
void mainloop(char **av, char**env)
{
	char *line = NULL;
	size_t buf_size = 0;
	int line_number = 0;
	(void) av;


	while (1)
	{
		if (isatty(0))
			write(1, ">_<: ", 5);

		if (_getline(&line, &buf_size, 0) == -1)
		{
			if (isatty(0))
			printf("\n");
			break;
		}

		if (just_spaces(line))
		{
			free(line);
			continue;
		}	
		strtrim(line);
		line_number++;
		execute_program(line, env, line_number);
		free(line);
	}
}

/**
 * handle_signal - handle ctrl + c
 * @sig: signal to handle
 */
void handle_signal(int sig)
{
	if (sig == SIGINT)
		printf("\n>_<: ");
	fflush(stdout);
}
int just_spaces(char *command)
{
	size_t i;

	for (i = 0; i < strlen(command) - 1; i++)
	{
		if (command[i] != ' ')
		{
			return (0);
		}
	}
	return (1);
}
