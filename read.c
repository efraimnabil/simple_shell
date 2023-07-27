#include "shell.h"

/**
 * read_command - Read a line of input from stdin.
 *
 * Return: A pointer to the buffer containing the input line,
 *         or NULL if an error occurs or end of file is reached.
 */
char *read_command(void)
{
	char buffer[BUFFER_SIZE];
	char *input = fgets(buffer, BUFFER_SIZE, stdin);

	if (input == NULL)
	{
		if (feof(stdin))
			return (NULL);

		perror("Read error");
		exit(EXIT_FAILURE);
	}

	buffer[strcspn(buffer, "\n")] = '\0';

	return (buffer);
}
