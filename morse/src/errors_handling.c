#include "morse.h"

void print_error() {
    write(2, "\"usage: ./morse \"str\"\n", mx_strlen("\"usage: ./morse \"str\"\n"));
    exit(1);
}

static void check_argc_num(int argc) {
    if (argc != 2) print_error();
}

static void check_allowed_symbols(char *str) {
    for (int i = 0; i < mx_strlen(str); i++) {
        if ((str[i]) != ' ' && str[i] != '.' && str[i] != '-' && str[i] != '\n') 
            if (!(str[i] == '\\' && str[i + 1] == 'n'))
                if (!(str[i] == 'n' && str[i - 1] == '\\'))
                    print_error();
    }
}

void check_command_line_arguments(int argc, char **argv) {
    check_argc_num(argc);
    check_allowed_symbols(argv[1]);
}
