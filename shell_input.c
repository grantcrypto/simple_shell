#include "shell.h"
/**
 * read_input - read user input or command
 * @input: user input orcommand
 * @size: size of input or command
 * Return: void
 */

void read_input(char *input, size_t size)
{
	if (fgets(input, size, stdin) == NULL)
	{
		if (feof(stdin))
		{
			shell_print("\n");
			exit(EXIT_SUCCESS);
		}
		else
		{
			shell_print("Error while reading input.\n");
			exit(EXIT_FAILURE);
		}
	}
	input[strcspn(input, "\n")] = '\0'; /* remove newline */
}

