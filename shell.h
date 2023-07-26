#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

size_t readCommand(char **);
void displayPrompt(void);
void executeCommand(char *);

#endif
