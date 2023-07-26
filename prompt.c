#include "shell.h"

/**
 * displayPrompt - Print the prompt prefix.
 */
void displayPrompt(void)
{
	write(STDOUT_FILENO, "$ ", 2);
}
