//
// Created by sammygros on 11/27/24.
//

#ifndef PRINT_H
#define PRINT_H
#include <sys/types.h>
#include <unistd.h>
#include <stdarg.h>
#include <stdio.h>

#define msg_welcome "Bienvenue dans le shell de l'ENSEA. \n Pour quitter, tapez 'exit'. \n "
#define msg_prompt "enseash"
#define msg_percentage "% "

void welcome();
void print_prompt();
void welcome_message();
void print_percentage();

#endif //PRINT_H
