#include "atbash.h"

int main(int argc, char **argv) {
    check_command_line_arguments(argc);
    decrypt(argv[1]);
    return 0;        
}
