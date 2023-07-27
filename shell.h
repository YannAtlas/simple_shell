#ifndef SHELL_H
#define SHELL_H

#include "shell.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

/* Function prototypes  */

void display_prompt(void);
char *read_command(void);
void execute_command(char *command);

#endif /* SHELL_H */
