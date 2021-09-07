#include "checkboard.h"

void print_error() {
    write(2, "usage: ./checkboard \"text\" \"alphabet\" \"num1\" \"num2\"\n", 
              mx_strlen("usage: ./checkboard \"text\" \"alphabet\" \"num1\" \"num2\"\n"));
    exit(1);
}

void check_command_line_arguments(int argc, char **argv) {
    if (argc != 5) print_error();
    for (int i = 0; i < mx_strlen(argv[2]); i++)
        if (mx_isdigit(argv[2][i]))
            print_error();
    
    if (mx_atoi(argv[2]) < 0 || mx_atoi(argv[3]) < 0)
        print_error();
    (void)argv;
}
