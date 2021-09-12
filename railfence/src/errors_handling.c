#include "railfence.h"

void print_error() {
    write(2, "usage: ./railfence \"str\" \"key\"\n", mx_strlen("usage: ./railfence \"str\" \"key\"\n"));
    exit(1);
}

void check_command_line_arguments(int argc, char **argv) {
    if (argc != 3) print_error();
    if (!argv[1]) print_error();
    if (mx_atoi(argv[2]) < 2) print_error();
}
