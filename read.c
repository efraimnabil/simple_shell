#include "shell.h"

/**
 * readCommand - Read a command from stdin.
 * @command: Buffer to store the command.
 *
 * Return: Number of characters read.
 */
size_t readCommand(char **command)
{
	size_t bufsize = 0;

    if (getline(command, &bufsize, stdin) == -1)
    {
        if (feof(stdin))
        {
            exit(EXIT_SUCCESS);
        }
        else
        {
            perror("readCommand");
            exit(EXIT_FAILURE);
        }
    }
    return (bufsize);
}
