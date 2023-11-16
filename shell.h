#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdbool.h>
#include <stdlib.h>
#include <sys/wait.h>

void shell_print(const char *string);
void display_shell_prompt(void);
void read_input(char *input, size_t size);
void execute_input(const char *input);

#endif
