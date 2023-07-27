#include "shell.h"

/**
 * execute_command - Executes the given command in a new process.
 * @command: The command to execute.
 */
void execute_command(char *command)
{
	char *argv[2] = {NULL, NULL};
	int status;
	pid_t pid = fork();

	if (pid == -1)
	{
		perror("Fork error");
		exit(EXIT_FAILURE);
	}
	else if (pid == 0)
	{
		char *token = strtok(command, " ");

		if (token != NULL)
		{
			argv[0] = token;
			if (execve(argv[0], argv, NULL) == -1)
			{
				perror("Command not found");
				exit(EXIT_FAILURE);
			}
		}
		else
		{
			exit(EXIT_SUCCESS);
		}
	}
	else
	{
		if (wait(&status) == -1)
		{
			perror("Wait error");
			exit(EXIT_FAILURE);
		}
	}
}
