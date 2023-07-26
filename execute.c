#include "shell.h"

/**
 * executeCommand - Executes the command.
 * @command: The command to be executed.
 */
void executeCommand(char *command)
{
	pid_t pid;
	int status;
	char *token;
	char *argv[10];

	for (int i = 0; i < 10; i++)
	{
		argv[i] = NULL;
	}

	int argIndex = 0;

	token = strtok(command, " \t\n");

	while (token != NULL && argIndex < 9)
	{
		argv[argIndex++] = token;
		token = strtok(NULL, " \t\n");
	}

	pid = fork();
	if (pid == 0)
	{
		if (execvp(argv[0], argv) == -1)
		{
			perror("Error");
			exit(EXIT_FAILURE);
		}
	}
	else if (pid < 0)
	{
		perror("Error");
	}
	else
	{
		wait(&status);
	}
}
