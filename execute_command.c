#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
/**
 * execute_input - execute command function
 * @input: command
 * Return: void
 */

void execute_input(const char *input)
{
	char *argv[] = {NULL};

		pid_t pid = fork(); /* fork new process */

		if (pid == -1)
		{
			perror("fork");
			exit(EXIT_FAILURE);
		}
		else if (pid == 0) /* child process, execute command */
		{
		if (execve(input, argv, NULL) == -1)
		{
		perror("execve");
		exit(EXIT_FAILURE);
		}
		exit(EXIT_FAILURE);
		}
		else
		{
			wait(NULL);
		}
}
