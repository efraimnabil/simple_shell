#include "shell.h"

/**
 * main - Entry point of the shell program.
 *
 * Return: Always 0.
 */
int main(void)
{
	char *command;

	if (is_interactive())
	{
		while (1)
		{
			display_prompt();
			command = read_command();

			if (command == NULL)
				break;

			execute_command(command);
		}
	}
	else
	{
		while ((command = read_command()) != NULL)
		{
			execute_command(command);
		}
	}

	return (0);
}
