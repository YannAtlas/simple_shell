#include "shell.h"

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <errno.h>

/**
 * execute_command - the function in charge of execution
 * @command :  the command type by the user
 *
 */
 void execute_command(char *command) {
	pid_t pid  = fork();

	if (pid < 0)
	{
		perror("fork");
		exit(EXIT_FAILURE);
	}
	else if (pid == 0)
	{
		char **args = malloc( 2* sizeof(char*));

		if (args == NULL) 
		{
			perror("malloc");
			exit(EXIT_FAILURE);
		}

		args[0] = command;
		args[1] = NULL;
		execve(command,	args, environ);

		perror(command);
		exit(EXIT_FAILURE);
	}
	else
	{
		int status;
		waitpid(pid, &status, 0);

		if (status != 0)
		{
			printf("./shell: No such file or directory\n");
		}
	}
}
