#include "caesar.h"

int main(int argc, char **argv) {
    check_command_line_arguments(argc, argv);
    decrypt(argv[1], mx_atoi(argv[2]));
}
