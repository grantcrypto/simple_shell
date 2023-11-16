#include "shell.h"

/**
 * main - main or source function
 * Return: 0
 */

int main(void)
{
	char input[200];

	while (true)
	{
		display_shell_prompt();
		read_input(input, sizeof(input));
		execute_input(input);
	}

	return(0);
}
