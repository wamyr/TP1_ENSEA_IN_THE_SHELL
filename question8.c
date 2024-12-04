//
// Created by sammygros on 11/28/24.
//

#include "question8.h"


void execute_command_pipe(char **argv, int *status, int position_pipe_or_bracket) { //resume: we'll store the result of the first command (before the |) in a file (descriptor |) and we'll use this file as input for the second command (after the pipe).
    int pipefd[2]; // Descriptors for pipe
    pid_t pid1, pid2; // children process

    // Create the pipe
    if (pipe(pipefd) == -1) {
        perror("pipe");
        exit(EXIT_FAILURE);
    }

    // Fork for the first child process (before `|`)
    pid1 = fork();
    if (pid1 == -1) {
        perror("fork");
        exit(EXIT_FAILURE);
    }

    if (pid1 == 0) {
        // Child 1 : executes the command before the `|`.
        close(pipefd[0]); // Closes the reading side of the pipe
        dup2(pipefd[1], STDOUT_FILENO); // Redirects stdout (the output) to the pipe
        close(pipefd[1]); // close descriptor

        argv[position_pipe_or_bracket] = NULL; // Replaces `|` with NULL to separate commands
        execvp(argv[0], argv); // executes the command before the `|`
        perror("execvp");
        exit(EXIT_FAILURE);
    }
    // Fork for the second child process (after `|`)
    pid2 = fork();
    if (pid2 == -1) {
        perror("fork");
        exit(EXIT_FAILURE);
    }

    if (pid2 == 0) {
        // Child 1 : executes the command after the `|`.
        close(pipefd[1]);
        dup2(pipefd[0], STDIN_FILENO); // Redirects stdin (the input) from the pipe
        close(pipefd[0]);
        execvp(argv[position_pipe_or_bracket + 1], &argv[position_pipe_or_bracket + 1]); // tip : input the address of the first token after the pipe to execute the command after the pipe
        perror("execvp");
        exit(EXIT_FAILURE);
    }

    // Parent: Closes both sides of the pipe
    close(pipefd[0]);
    close(pipefd[1]);

    // Wait for both child
    waitpid(pid1, status, 0);
    waitpid(pid2, status, 0);

}