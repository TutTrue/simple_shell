#include "shell.h"

int main(int ar, char **av, char **env)
{
	signal(SIGINT, handle_signal);
	mainloop(ar, av, env);
	return (0);
}
void mainloop(int ar, char **av, char**env)
{
	char *line = NULL;
	size_t buf_size = 0;

	while (1)
	{
		if (isatty(0))
			write(1, ">_<: ", 5);

		if (_getline(&line, &buf_size, 0) == -1)
		{
			printf("\n");
			break;
		}

		if (just_spaces(line))
		{
			free(line);
			continue;
		}	
		strtrim(line);
		execute_program(line, env);
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
    for (size_t i = 0; i < strlen(command); i++)
    {
        if (command[i] != ' ')
        {
            return (0);
        }
    }
    return (1);
}
