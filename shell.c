#include "shell.h"

int main(int ar, char **av, char **env)
{
	signal(SIGINT, handle_signal);
	mainloop();
}
void mainloop()
{
	char *line = NULL;
	size_t buf_size = 0;
	while (1)
	{
		write(1, ">_<: ", 5);
		
		if (_getline(&line, &buf_size, 0) == -1)
		{
			break;
		}

		if (just_spaces(line))
		{
			free(line);
			continue;
		}
		strtrim(line);
		free(line);
	}
}

int just_spaces()
{
	return (0);
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
void free_all(char *line)
{
}	
