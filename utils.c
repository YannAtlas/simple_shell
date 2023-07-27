#include "shell.h"

#include <stdio.h>
#include <stlid.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

/*
 * *read_commend read the comand type by the user
 *
 * Return: the organised command
 */
char *read_command(void) 
{
	char *command = NULL;
	size_t bufsize = 0;
	ssize_t bytes_read = getline(&command, &bufsize, stdin);

	if (bytes_read == -1)
	{
		free(command);
		return (NULL);
	}

	size_t cmd_len = strlen(command);

	if ( cmd_len > 0 && command[cmd_len - 1] == "\n")
	{
		command[cmd_len - 1] = "\0";
	}

	return  (command);
}
