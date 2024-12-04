//
// Created by sammygros on 11/27/24.
//

#include "question3.h"

int command_exit(char *command) {
    if (strcmp(command, "exit") == False) {
        // si je veux mettre bye bye c'est ici
        return True ;
    }
    return False;
}
