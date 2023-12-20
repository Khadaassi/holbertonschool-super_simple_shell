#ifndef SHELL_H
#define SHELL_H
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/stat.h>

extern char **environ;

/* read_line.c */
char *read_line(void);

/* splitter.c */
char **splitter(char *input_line, char *delimiters, char separator);

/* shell_create_child.c */
void create_child_process(char *line, char **args, char **av);

/* shell_aux_function.c */
void signal_handler(int signal_number);
int count_separator(char *line, char separator);
int has_spaces(char *input);

/* shell_execute.c */
char *search_executable_in_path(char *executable);
char *get_path_variable(void);
void print_environment(void);

/* free.c */
void free_arguments(char **arguments);

#endif
