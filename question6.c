//
// Created by sammygros on 11/27/24.
//

#include "question6.h"

void execute_command_complex(char **argv, int *status) {
    if (fork() == 0) {
        execvp(argv[0],argv);
        exit(1);
    }
    else {
        wait(status);
    }
}

void separate_arguments(char *command, char **argv) {
    int i = 0;
    char *token = strtok(command, " ");  // Séparation par espaces
    // Tokenize et remplir argv
    while (token != NULL && i < MAXSIZE - 1) {  // éviter de dépasser MAXSIZE
        argv[i] = token;  // Assigner le token à argv[i]
        token = strtok(NULL, " ");  // Passer au token suivant
        i++;
    }
    argv[i] = NULL;  // Terminer le tableau argv par NULL pour execvp
}