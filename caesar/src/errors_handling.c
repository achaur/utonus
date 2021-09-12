#include "caesar.h"

void print_error() {
    write(2, "usage: ./caesar \"str\" \"key\"\n", mx_strlen("usage: ./caesar \"str\" \"key\"\n"));
    exit(1);
}

void check_command_line_arguments(int argc, char **argv) {
    if (argc != 3) print_error();
    if (!(mx_atoi(argv[2]) >= 1 && mx_atoi(argv[2]) <= 25))
        print_error();
}
