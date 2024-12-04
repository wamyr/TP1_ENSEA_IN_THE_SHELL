//
// Created by sammygros on 11/27/24.
//

#include "question3.h"

int command_exit(char *command) {
    if (strcmp(command, "exit") == 0) {
        // no bye bye message...
        return True ;
    }
    return False;
}
