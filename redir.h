#ifndef REDIR_H
#define REDIR_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>

void split(char *cmd, char *args[]);
pid_t fork_process();
void execute(char *args[]);
void redir_in(const char *input_file);
void redir_out(const char *output_file);

#endif
