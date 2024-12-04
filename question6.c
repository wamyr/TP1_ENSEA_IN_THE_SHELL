//
// Created by sammygros on 11/27/24.
//

#include "question6.h"

void execute_command_complex(char **argv, int *status) {
    if (fork() == 0) {
        execvp(argv[0],argv); //with argv it's execvp that should be used: first argument of execvp: the command, then the second argument: the arguments of the shell command received.
        exit(1);
    }
    else {
        wait(status);
    }
}

void separate_arguments(char *command, char **argv) {
    int i = 0;
    char *token = strtok(command, " ");  // each token is separated by a space, as if each word were separated from a sentence
    while (token != NULL && i < MAXSIZE - 1) {  //each element of argv will be replaced by a command argument (argument or “word” because tokens are separated by spaces) starting with the basic command which will be argv[0].
        argv[i] = token;
        token = strtok(NULL, " ");  // move on to the next token
        i++;
    }
    argv[i] = NULL;  //terminate the array with NULL for execvp to run correctly
}