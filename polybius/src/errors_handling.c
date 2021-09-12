#include "polybius.h"

void print_error() {
    write(2, "usage: ./polybius \"str\"\n", mx_strlen("usage: ./polybius \"str\"\n"));
    exit(1);
}

void check_command_line_arguments(int argc, char **argv) {
    if (argc != 2) print_error();
    if (!argv[1]) print_error();
    int i;
    for (i = 0; i < mx_strlen(argv[1]); i++)
        if (mx_isalpha(argv[1][i]))
            if ((argv[1][i] != 'a' && argv[1][i] != 'b' && argv[1][i] != 'c' && argv[1][i] != 'd' && argv[1][i] != 'e' && argv[1][i] != 'f') &&
                (argv[1][i] != 'A' && argv[1][i] != 'B' && argv[1][i] != 'C' && argv[1][i] != 'D' && argv[1][i] != 'E' && argv[1][i] != 'F'))
                print_error();
}
