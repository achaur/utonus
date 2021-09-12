#include "atbash.h"

void print_error() {
    write(2, "usage: ./atbash \"str\"\n", mx_strlen("usage: ./atbash \"str\"\n"));
    exit(1);
}

void check_command_line_arguments(int argc) {
    if (argc != 2) print_error();
}
