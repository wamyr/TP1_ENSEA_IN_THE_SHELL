//
// Created by sammygros on 11/28/24.
//

#include "question7.h"

#include <stdio.h>
#include <string.h>
#include <unistd.h>

int identify_pipe_and_brackets(char **argv, int* position_pipe_or_bracket) {
    int i = 0 ;
    while(argv[i] != NULL) {
        if (strcmp(argv[i], "|") == 0) {
            *position_pipe_or_bracket = i;
            return HAVE_PIPE;
        } else if (strcmp(argv[i], "<") == 0) {
            *position_pipe_or_bracket = i;
            return HAVE_LESSER_THAN;
        } else if (strcmp(argv[i], ">") == 0) {
            *position_pipe_or_bracket = i;
            return HAVE_GREATER_THAN;
        }
        i ++ ;
    }
    return NO_PIPE_NO_LESSER_THAN_NO_GREATER_THAN;
}

void execute_command_lesser_than(char **argv, int *status, int position_pipe_or_bracket) {
    write(STDOUT_FILENO, "lesser_than \n", sizeof("lesser_than \n"));
}

void execute_command_greater_than(char **argv, int *status, int position_pipe_or_bracket) {
    write(STDOUT_FILENO, "greater_than \n", sizeof("greater_than \n"));
}