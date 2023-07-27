#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>

#define BUFFER_SIZE 1024

void execute_command(char *command);
void display_prompt(void);
char *read_command(void);
int is_interactive(void);

#endif /* SHELL_H */
