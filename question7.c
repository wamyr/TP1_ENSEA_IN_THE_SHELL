//
// Created by sammygros on 11/28/24.
//

#include "question7.h"

#include <stdio.h>
#include <string.h>
#include <unistd.h>

int identify_pipe_and_brackets(char **argv, int* position_pipe_or_bracket) { //compare each element of argv to see if there are < > or |
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
    pid = fork(); // child process
    if (pid == -1) {
        perror("fork");
        exit(EXIT_FAILURE);
    }
    if (pid == 0) {
        int fd = open(argv[position_pipe_or_bracket + 1], O_RDONLY);// Opens the file mentioned after '<'
        if (fd == -1) {
            perror("open");
            exit(EXIT_FAILURE);
        }
        dup2(fd, STDIN_FILENO); //Redirects stdin (the input) to the file, opened by descriptor fd
        close(fd); // closes the fd descriptor
        argv[position_pipe_or_bracket] = NULL; // tip: replace < with NULL so that execvp stops at NULL and correctly executes the preceding command
        execvp(argv[0], argv);
        perror("execvp");
        exit(EXIT_FAILURE);
    }
    waitpid(pid, status, 0); // waiting for child
}

void execute_command_greater_than(char **argv, int *status, int position_pipe_or_bracket) {
    pid_t pid;
    pid = fork(); // child process
    if (pid == -1) {
        perror("fork");
        exit(EXIT_FAILURE);
    }
    if (pid == 0) {
        int fd = open(argv[position_pipe_or_bracket + 1], O_CREAT | O_WRONLY | O_TRUNC, PERMISSION_TO_WRITE_OWNER); // Opens or creates the file named after `>`.
        if (fd == -1) {
            perror("open");
            exit(EXIT_FAILURE);
        }
        dup2(fd, STDOUT_FILENO); //Redirects stdout (the output) to the file, opened by descriptor fd
        close(fd);// closes the fd descriptor
        argv[position_pipe_or_bracket] = NULL;
        execvp(argv[0], argv);
        perror("execvp");
        exit(EXIT_FAILURE);
    }
    waitpid(pid, status, 0); // waiting for child
}
