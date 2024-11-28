//
// Created by sammygros on 11/27/24.
//

#include "question2.h"


void prompt_reading(char *command){
    int numberOfelements = (int) read(STDIN_FILENO, command, MAXSIZE);
    command[numberOfelements-1] = '\0';
}

void execute_command(char *command, int *status) {
    if (fork() == 0) {
        execlp(command, command, NULL);
        exit(1);
    }
    else {
        wait(status);
    }
}