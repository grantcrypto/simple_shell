#include "shell.h"
/**
 * main - execve function
 *
 * Return: Always 0.
 */
int main(void)
{
	char *argv[] = {"ls", "-l", NULL};
	char *envp[] = {NULL};

	printf("Before execve\n");
	if (execve("/bin/ls", argv, envp) == -1)
	{
	perror("Error:");
	}
	printf("After execve\n");
	return (0);
}
