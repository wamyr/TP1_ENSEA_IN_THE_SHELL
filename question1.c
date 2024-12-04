//
// Created by sammygros on 11/27/24.
//

#include "question1.h"


void welcome_message() {
    write(STDOUT_FILENO, msg_welcome, sizeof(msg_welcome));
}

void print_prompt() {
    write(STDOUT_FILENO, msg_prompt, sizeof(msg_prompt));
}

void print_percentage() {
    write(STDOUT_FILENO, msg_percentage, sizeof(msg_percentage));
}

void welcome() {
    welcome_message();
    //print_prompt();
}
