#include "shell.h"
/**
 * execute_input - function that executes command
 * @input: input or command to be executed
 * Return: 0
 */
int execute_input()
{
	pid_t child_pid = fork(); /* create a child process */

	if (child_pid == -1)
	{
		perror("fork");
		exit(EXIT_FAILURE);
	}
	else if (child_pid == 0)
	{
		printf("child process executing...\n");
		exit(EXIT_SUCCESS);
	}
	else
	{
		int status;
		pid_t terminated_child_pid = wait(&status);

		if (terminated_child_pid == -1)
		{
			perror("wait");
			exit(EXIT_FAILURE);
		}

		printf("Child process terminated.\n");

		if (WIFEXITED(status)) /* Child process terminated normally */
		{
			printf("Child process exited with status %d\n", WEXITSTATUS(status));
		}
		else if (WIFSIGNALED(status)) /* child process terminated by a signal */
		{
			printf("Child process terminated by a signal %d\n", WTERMSIG(status));
		}
	}
	return (0);
}
