//
// Created by sammygros on 11/28/24.
//

#ifndef QUESTION8_H
#define QUESTION8_H
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>
#include <sys/types.h>


void execute_command_pipe(char **argv, int *status, int position_pipe_or_bracket);
#endif //QUESTION8_H
