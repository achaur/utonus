#pragma once

#include <unistd.h>
#include <stdbool.h>
#include <stdlib.h>

void check_command_line_arguments(int argc, char **argv);
int mx_strlen(const char *s);
void mx_printchar(char c);
void print_error();
void decrypt(char *text, char *str, int key1, int key2);
char *mx_strnew(const int size);
int mx_atoi(char *str);
void mx_strdel(char **str);
bool mx_isdigit(char c);
