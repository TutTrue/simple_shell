#include "shell.h"

void hande_pwd()
{
	char cwd[BUFSIZE];

	if (getcwd(cwd, sizeof(cwd)))
	{
		printf("%s\n", cwd);
	}
}
