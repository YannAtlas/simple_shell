#include "shell.h"

#include <stdio.h>
#include <stdlib.h>

/**
 * main - the main funct_ion of the code
 *
 * Return: nothinh
 */
int main(void)
{
	char *command;

	while (1)
	{
		display_prompt();
		command = read_command();

		if (command  == NULL)
		{
			printf("\n");
			break;
		}

		execute_command(command);
		free(command);
	}

	return (0);
}

