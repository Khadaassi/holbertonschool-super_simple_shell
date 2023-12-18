#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include <sys/stat.h>

char *_getenv(const char *name);
char *get_command(char *command);
char **split_string(char *buffer, char *del);