//
// Created by sammygros on 11/28/24.
//

#include "question8.h"


void execute_command_pipe(char **argv, int *status, int position_pipe_or_bracket) {
    int pipefd[2]; // Descripteurs pour le pipe
    pid_t pid1, pid2; // Processus enfants

    // Créer le pipe
    if (pipe(pipefd) == -1) {
        perror("pipe");
        exit(EXIT_FAILURE);
    }

    // Fork pour le premier processus (avant le `|`)
    pid1 = fork();
    if (pid1 == -1) {
        perror("fork");
        exit(EXIT_FAILURE);
    }

    if (pid1 == 0) {
        // Enfant 1 : exécute la commande avant le `|`
        close(pipefd[0]); // Ferme le côté lecture du pipe
        dup2(pipefd[1], STDOUT_FILENO); // Redirige stdout vers le pipe
        close(pipefd[1]); // Ferme le descripteur inutilisé

        // Préparer les arguments pour la commande avant le `|`
        argv[position_pipe_or_bracket] = NULL; // Remplace `|` par NULL pour séparer les commandes
        execvp(argv[0], argv); // Exécute la commande avant le `|`
        perror("execvp"); // Si exec échoue
        exit(EXIT_FAILURE);
    }

    // Fork pour le deuxième processus (après le `|`)
    pid2 = fork();
    if (pid2 == -1) {
        perror("fork");
        exit(EXIT_FAILURE);
    }

    if (pid2 == 0) {
        // Enfant 2 : exécute la commande après le `|`
        close(pipefd[1]); // Ferme le côté écriture du pipe
        dup2(pipefd[0], STDIN_FILENO); // Redirige stdin depuis le pipe
        close(pipefd[0]); // Ferme le descripteur inutilisé

        // Préparer les arguments pour la commande après le `|`
        execvp(argv[position_pipe_or_bracket + 1], &argv[position_pipe_or_bracket + 1]); // Exécute la commande après le `|`
        perror("execvp"); // Si exec échoue
        exit(EXIT_FAILURE);
    }

    // Parent : Ferme les deux côtés du pipe
    close(pipefd[0]);
    close(pipefd[1]);

    // Attend les deux enfants
    waitpid(pid1, status, 0);
    waitpid(pid2, status, 0);

}