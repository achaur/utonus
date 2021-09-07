#pragma once

#include <unistd.h>
#include <stdbool.h>
#include <stdlib.h>

void check_command_line_arguments(int argc, char **argv);
int mx_strlen(const char *s);
void mx_printchar(char c);
void print_error();
void decrypt(char *str, int key);
char *mx_strnew(const int size);
int mx_atoi(char *str);
void mx_strdel(char **str);
