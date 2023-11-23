#include "shell.h"

/**
 * command_execute - execute a command
 * @input: command to be executed
 * Return: void
 */

void command_execute(const char *input)
{
	char *argv[] = {"/bin/ls", NULL};

	pid_t pid = fork();

	if (pid == -1)
	{
		perror("fork");
		exit(EXIT_FAILURE);
	}
	else if (pid == 0)
	{
		if (execve(input, argv, NULL) == -1)
		{
			perror("simple_shell$");
			exit(EXIT_FAILURE);
		}
	}
		else
		{
			wait(NULL);
		}
}

/**
 * main - main function
 * Return: 0
 */

#define COMMAND_LENGTH 100

int main(void)
{
	char input[COMMAND_LENGTH];

	while (1)
	{
		shell_print("$");

		if (fgets(input, sizeof(input), stdin) == NULL)
		{
			shell_print("\n");
			break;
		}

	input[strcspn(input, "\n")] = '\0';

	command_execute(input);
	}

	return (0);
}
