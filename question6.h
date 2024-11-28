//
// Created by sammygros on 11/27/24.
//

#ifndef QUESTION6_H
#define QUESTION6_H
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
#include <stdio.h>

#define MAXSIZE 1024

void execute_command_complex(char *command, int *status);
void separate_command(char *command, char **argv);

#endif //QUESTION6_H
