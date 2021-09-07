#pragma once

#include <stdbool.h>
#include <unistd.h>
#include <stdlib.h>

void check_command_line_arguments(int argc, char **argv);
void dichotomic_search(char *str);
int mx_strlen(const char *s);
void mx_printchar(char c);
bool mx_isspace(char c);
int mx_strcmp(const char *s1, const char *s2);
void print_error();
