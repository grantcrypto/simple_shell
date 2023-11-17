#include "shell.h"
/**
 * execute_input - function that executes command
 *
 * Return: void
 */

void execute_input(const char *command)
{

	pid_t pid = fork(); /* creating child process */

	if (pid == -1)
	{
		perror("fork");
		exit(EXIT_FAILURE);
	}
	else if (pid == 0)
	{
		/* child process */
		execlp(command, command, (char *)NULL);
		perror("./shell");
		exit(EXIT_FAILURE);
	}
	else
	{
		wait(NULL);
	}
}
