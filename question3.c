//
// Created by sammygros on 11/27/24.
//

#include "question3.h"

int command_exit(char *command) {
    if (strcmp(command, "exit") == 0) {
        // si je veux mettre bye bye c'est ici
        return 1 ;
    }
    return 0;
}
