//
// Created by sammygros on 11/27/24.
//

#include "question2.h"


void prompt_reading(char *command){
    int numberOfelements = (int) read(STDIN_FILENO, command, MAXSIZE);
    command[numberOfelements-1] = '\0'; //make sure the last element of command is '\0' in order to be readable by execlp
}

void execute_command(char *command, int *status) {
    if (fork() == 0) { // child execute command
        execlp(command, command, NULL);
        exit(1); //make sure to finish child process, in order to avoid child process "superposition"
    }
    else { //father : waiting for child to finish
        wait(status);
    }
}