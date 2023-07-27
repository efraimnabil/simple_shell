#include "shell.h"

/**
 * executeCommand - Executes the command.
 * @command: The command to be executed.
 */
void executeCommand(char *command)
{
	pid_t pid;
	char *envp[1] = {NULL};
	unsigned int argIndex = 0;
	char *argv[100];
	char *token = strtok(command, " \t\n");
	unsigned int i;

	for (i = 0; i < 100; i++)
		argv[i] = NULL;

	while (token != NULL)
	{
		argv[argIndex] = token;
		argIndex++;
		token = strtok(NULL, " \t\n");
	}
	if (argIndex > 1)
	{
		write(STDERR_FILENO, "/hshbb: No such file or directory\n", 34);
		return;
	}
	argv[argIndex] = NULL;
	pid = fork();
	if (pid == 0)
	{
		if (execve(argv[0], argv, envp) == -1)
		{
			perror("./hshd");
			exit(EXIT_FAILURE);
		}
	}
	else if (pid < 0)
	{
		perror("./hshf");
	}
	else
	{
		wait(NULL);
	}
}
