//
// Created by sammygros on 11/27/24.
//

#ifndef QUESTION2_H
#define QUESTION2_H
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>


#define MAXSIZE 1024

void prompt_reading(char *command);
void execute_command(char *command, int *status);

#endif //QUESTION2_H
