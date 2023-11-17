#include "shell.h"
/**
 * execute_input - function that executes command
 *
 * Return: void
 */

void execute_input(void)
{
	char *const argv[] = {"ls", NULL};

	pid_t pid = fork(); /* creating child process */

	if (pid == -1)
	{
		perror("fork");
		exit(EXIT_FAILURE);
	}
	else if (pid == 0)
	{
		/* child process */
		execve("/bin/ls", argv, NULL);
		perror("execve");
		exit(EXIT_FAILURE);
	}
	else
	{
		wait(NULL);
	}
}
