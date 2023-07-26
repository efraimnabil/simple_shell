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
		displayPrompt();
		readCommand(&buf);
		executeCommand(buf);
	}
	return (0);
}
