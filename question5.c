//
// Created by sammygros on 11/27/24.
//

#include "question5.h"

struct timespec start_time;
struct timespec end_time;

void print_time(int time) {
    char message_to_sent[MAXSIZE] = {'\0'};
    snprintf(message_to_sent, sizeof(message_to_sent),msg_time, time);
    write(STDOUT_FILENO, message_to_sent, sizeof(message_to_sent));
}

void start_timer() {
    clock_gettime(CLOCK_MONOTONIC, &start_time);
}

void end_timer() {
    clock_gettime(CLOCK_MONOTONIC, &end_time);
}

int get_time() {
    return ((int) ((double)(end_time.tv_sec - start_time.tv_sec)*1e3 + (double)(end_time.tv_nsec - start_time.tv_nsec) / 1e6)) ;
}
