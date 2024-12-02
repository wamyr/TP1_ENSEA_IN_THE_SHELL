//
// Created by sammygros on 11/28/24.
//

#include "question7.h"

#include <stdio.h>
#include <string.h>
#include <unistd.h>

int identify_pipe_and_brackets(char **argv, int* position_pipe_or_bracket) {
    int i = 0 ;
    while(argv[i] != NULL) {
        if (strcmp(argv[i], "|") == 0) {
            *position_pipe_or_bracket = i;
            return HAVE_PIPE;
        } else if (strcmp(argv[i], "<") == 0) {
            *position_pipe_or_bracket = i;
            return HAVE_LESSER_THAN;
        } else if (strcmp(argv[i], ">") == 0) {
            *position_pipe_or_bracket = i;
            return HAVE_GREATER_THAN;
        }
        i ++ ;
    }
    return NO_PIPE_NO_LESSER_THAN_NO_GREATER_THAN;
}

void execute_command_lesser_than(char **argv, int *status, int position_pipe_or_bracket) {
    pid_t pid;

    pid = fork(); // Création du processus enfant
    if (pid == -1) {
        perror("fork");
        exit(EXIT_FAILURE);
    }

    if (pid == 0) {
        // Enfant
        // Ouvre le fichier mentionné après `<`
        int fd = open(argv[position_pipe_or_bracket + 1], O_RDONLY);
        if (fd == -1) {
            perror("open");
            exit(EXIT_FAILURE);
        }

        // Redirige stdin vers le fichier
        dup2(fd, STDIN_FILENO);
        close(fd); // Ferme le descripteur inutilisé

        // Prépare la commande avant `<`
        argv[position_pipe_or_bracket] = NULL; // Remplace `<` par NULL
        execvp(argv[0], argv); // Exécute la commande
        perror("execvp");
        exit(EXIT_FAILURE);
    }

    // Parent
    waitpid(pid, status, 0); // Attend l'enfant
}

void execute_command_greater_than(char **argv, int *status, int position_pipe_or_bracket) {
    pid_t pid;
    pid = fork(); // Création du processus enfant

    if (pid == -1) {
        perror("fork");
        exit(EXIT_FAILURE);
    }

    if (pid == 0) {
        // Enfant
        // Ouvre ou crée le fichier mentionné après `>`
        int fd = open(argv[position_pipe_or_bracket + 1], O_CREAT | O_WRONLY | O_TRUNC, PERMISSION_TO_WRITE_OWNER);
        if (fd == -1) {
            perror("open");
            exit(EXIT_FAILURE);
        }

        // Redirige stdout vers le fichier
        dup2(fd, STDOUT_FILENO);
        close(fd); // Ferme le descripteur inutilisé

        // Prépare la commande avant `>`
        argv[position_pipe_or_bracket] = NULL; // Remplace `>` par NULL
        execvp(argv[0], argv); // Exécute la commande
        perror("execvp");
        exit(EXIT_FAILURE);
    }

    // Parent
    waitpid(pid, status, 0); // Attend l'enfant
}
