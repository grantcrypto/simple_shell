#include "shell.h"

/**
* shell_print - print the string
* @string: input string
* Return: void
*/
void shell_print(const char *string, ...)
{
	write(STDOUT_FILENO, string, strlen(string));
}
