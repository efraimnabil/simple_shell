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
	char *envp[1] = { NULL };
	unsigned int argIndex = 0;
	unsigned int i;

	for (i = 0; i < 10; i++)
	{
		argv[i] = NULL;
	}

	token = strtok(command, " \t\n");

	while (token != NULL && argIndex < 9)
	{
		argv[argIndex++] = token;
		token = strtok(NULL, " \t\n");
	}

	pid = fork();
	if (pid == 0)
	{
		if (execve(argv[0], argv, envp) == -1)
		{
			perror("./hsh");
			exit(EXIT_FAILURE);
		}
	}
	else if (pid < 0)
	{
		perror("./hsh");
	}
	else
	{
		wait(&status);
	}
}
