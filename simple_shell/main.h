#ifndef MAIN_H
#define MAIN_H

#include <errno.h>
#include <fcntl.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>


char *_getenv(const char *name);
char *get_command(char *command);
char **split_string(char *buffer, char *del);

extern char **environ;

#endif /* MAIN_H */
