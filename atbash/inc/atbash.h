#pragma once

#include <unistd.h>
#include <stdbool.h>
#include <stdlib.h>

bool mx_isalpha(int c);
void check_command_line_arguments(int argc);
int mx_strlen(const char *s);
void mx_printchar(char c);
bool mx_isspace(char c);
void print_error();
void decrypt(char *str);
char *mx_strnew(const int size);
