#include "shell.h"

/**
 * command_execute - function that execute command
 * @input: command inputted
 * Return: void
 */

#define COMMAND_LENGTH 100

void command_execute(const char *input)
{
	char *argv[] = {NULL};

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

int main(void)
{
	char input[COMMAND_LENGTH];

	while (1)
	{
		shell_print(crypto_shell$);

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
