//
// Created by sammygros on 11/27/24.
//

#ifndef QUESTION5_H
#define QUESTION5_H
#include <stdio.h>
#include <unistd.h>
#include <time.h>

#define MAXSIZE 1024
#define msg_time " | %d ms] "

extern struct timespec start_time ;
extern struct timespec end_time ;

void print_time(int time);
void start_timer();
void end_timer();
int get_time();

#endif //QUESTION5_H
