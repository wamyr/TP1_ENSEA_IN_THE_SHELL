//
// Created by sammygros on 11/27/24.
//

#include "question4.h"


void write_message(char *message, int val) {
    char message_to_write[MAXSIZE] = {'\0'};
    snprintf(message_to_write, sizeof(message_to_write), message, val); //replace %d in our message with the value val
    write(STDOUT_FILENO, message_to_write, sizeof(message_to_write));
}

void print_status(int status) {
    if (WIFEXITED(status)) {
        write_message(MSG_EXIT, WEXITSTATUS(status));
    }
    else if (WIFSIGNALED(status)) {
        write_message(MSG_SIGN, WTERMSIG(status));
    }
}