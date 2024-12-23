//
// Created by sammygros on 11/28/24.
//

#ifndef QUESTION7_H
#define QUESTION7_H

#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>

#define HAVE_PIPE 1
#define HAVE_LESSER_THAN 2
#define HAVE_GREATER_THAN 3
#define NO_PIPE_NO_LESSER_THAN_NO_GREATER_THAN 4
#define PERMISSION_TO_WRITE_OWNER 0644 //owner can write

int identify_pipe_and_brackets(char **argv, int *position_pipe_or_bracket);
void execute_command_lesser_than(char **argv, int *status, int position_pipe_or_bracket);
void execute_command_greater_than(char **argv, int *status, int position_pipe_or_bracket);

#endif //QUESTION7_H
