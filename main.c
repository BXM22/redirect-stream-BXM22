#include <stdio.h>
#include "redir.h"

int main(int argc, char *argv[]) {

    char *inp = argv[1];
    char *cmd = argv[2];
    char *out = argv[3];

    char *args[256];
    split(cmd, args);

    pid_t pid = fork_process();

    if (pid < 0) {
        perror("fork");
        exit(EXIT_FAILURE);
    } else if (pid == 0) {
        redir_in(inp);
        redir_out(out);
        execute(args);
    }
    return 0;
}
