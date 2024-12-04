//
// Created by sammygros on 11/27/24.
//

#ifndef QUESTION4_H
#define QUESTION4_H
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>

#define MAXSIZE 1024
#define MSG_EXIT "[exit:%d"
#define MSG_SIGN "[sign:%d"

void print_status(int status);
void write_message(char *message, int val);
#endif //QUESTION4_H

