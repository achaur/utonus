#pragma once

#include <unistd.h>
#include <stdbool.h>
#include <stdlib.h>

bool mx_isalpha(int c);
void check_command_line_arguments(int argc, char **argv);
int mx_strlen(const char *s);
void mx_printchar(char c);
bool mx_isspace(char c);
void print_error();
void decrypt(char *str);
char *mx_strnew(const int size);
int mx_atoi(char *str);
void mx_strdel(char **str);
int mx_strcmp(const char *s1, const char *s2);
