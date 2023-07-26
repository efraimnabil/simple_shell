#include "shell.h"

/**
 * readCommand - Read a command from stdin.
 * @command: Buffer to store the command.
 *
 * Return: Number of characters read.
 */
size_t readCommand(char **command)
{
	size_t i = 0;

	i = getline(command, &i, stdin);
	if (i == -1)
	{
		printf("\n");
		exit(1);
	}
	(*command)[i - 1] = '\0';
	return (i);
}
