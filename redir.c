#include "redir.h"

void split(char *cmd, char *args[]) {
    int i = 0;
    char *token = strtok(cmd, " ");
    while (token != NULL && i < 255) {
        args[i++] = token;
        token = strtok(NULL, " ");
    }
    args[i] = NULL;
}

pid_t fork_process() {
    return fork();
}

void execute(char *args[]) {
    execvp(args[0], args);
    perror("execvp");
    exit(EXIT_FAILURE);
}


void redir_in(const char *input_file) {
    if (strcmp(input_file, "-") != 0) {
        int in_fd = open(input_file, O_RDONLY);
        if (in_fd < 0) {
            perror("open input");
            exit(EXIT_FAILURE);
        }
        dup2(in_fd, STDIN_FILENO);
        close(in_fd);
    }
}

void redir_out(const char *output_file) {
    if (strcmp(output_file, "-") != 0) {
        int out_fd = open(output_file, O_WRONLY | O_CREAT | O_TRUNC, 0666);
        if (out_fd < 0) {
            perror("open output");
            exit(EXIT_FAILURE);
        }
        dup2(out_fd, STDOUT_FILENO);
        close(out_fd);
    }
}
