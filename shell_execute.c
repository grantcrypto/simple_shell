#include "shell.h"
/**
 * execute_input - function that executes command
 * @input: input or command to be executed
 * Return: void
 */
void execute_input(const char *input)
{
	pid_t child_pid = fork(); /* create a child process */

	if (child_pid == -1)
	{
		perror("fork");
		exit(EXIT_FAILURE);
	}
	else if (child_pid == 0)
	{
		execlp(input, input, (char *)NULL);
		perror("execlp");
		exit(EXIT_FAILURE);
	}
	else
	{
		wait(NULL);
	}
}
