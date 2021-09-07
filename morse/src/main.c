#include "morse.h"

int main(int argc, char **argv) {
    check_command_line_arguments(argc, argv);
    dichotomic_search(argv[1]);
    return 0;        
}
