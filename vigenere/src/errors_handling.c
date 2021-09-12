#include "vigenere.h"

void print_error() {
    write(2, "usage: ./vigenere \"str\" \"key\"\n", mx_strlen("usage: ./vigenere \"str\" \"key\"\n"));
    exit(1);
}

void check_command_line_arguments(int argc, char **argv) {
    if (argc != 3) print_error();
    if (!argv[1] || !argv[2]) print_error();
}
