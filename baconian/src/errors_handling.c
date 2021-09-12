#include "baconian.h"

void print_error() {
    write(2, "usage: ./baconian \"str\"\n", mx_strlen("usage: ./baconian \"str\"\n"));
    exit(1);
}

void check_command_line_arguments(int argc, char **argv) {
    if (argc != 2) print_error();
    if (!argv[1]) print_error();
}
