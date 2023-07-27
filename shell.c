#include "shell.h"

/**
 * main - Entry point of the program.
 *
 * Return: Always 0 (success).
 */
int main(void)
{
	char *buf;

	while (1)
	{
		if (isatty(STDIN_FILENO))
			displayPrompt();
		buf = NULL;
		readCommand(&buf);
		executeCommand(buf);
		free(buf);
	}
	return (0);
}
