#include "morse.h"

static bool end_of_letter(char *str, int i) {
    if (str[i + 1] == ' ' || (i + 1 == mx_strlen(str)) || str[i + 1] == '\n' || (str[i + 1] == '\\' && str[i + 2] == 'n'))
        return true;
    return false;
}

void dichotomic_search(char *str) {
    int i = 0, index = 0; 
    char buf[mx_strlen(str) / 2];

    for (int i = 0; i < mx_strlen(str) / 2; i++)
        buf[i] = '\0';
    while (i < mx_strlen(str)) {
        if (str[i] == '.') {
            if (end_of_letter(str, i)) {
                buf[index++] = 'e';
                i++;
            }
            else if (str[i + 1] == '.') {
                if (end_of_letter(str, i + 1)) {
                    buf[index++] = 'i';
                    i += 2;
                } 
                else if (str[i + 2] == '.') {
                    if (end_of_letter(str, i + 2)) {
                        buf[index++] = 's';
                        i += 3;
                    }
                    else if (str[i + 3] == '.') {
                        if (end_of_letter(str, i + 3)) {
                            buf[index++] = 'h';
                            i += 4;
                        }
                        else if (str[i + 4] == '.' && end_of_letter(str, i + 4)) {
                            buf[index++] = '.';
                            i += 5;
                        }
                        else print_error();
                    }
                    else if (str[i + 3] == '-') {
                        if (end_of_letter(str, i + 3)) {
                            buf[index++] = 'v';
                            i += 4;
                        }
                        else print_error();
                    }
                }
                else if (str[i + 2] == '-') {
                    if (end_of_letter(str, i + 2)) {
                        buf[index++] = 'u';
                        i += 3;
                    }
                    else if (str[i + 3] == '.') {
                        if (end_of_letter(str, i + 3)) {
                            buf[index++] = 'f';
                            i += 4;
                        }
                    }
                    else print_error();
                }              
            }
            else if (str[i + 1] == '-') {
                if (end_of_letter(str, i + 1)) {
                    buf[index++] = 'a';
                    i += 2;
                }
                else if (str[i + 2] == '.') {
                    if (end_of_letter(str, i + 2)) {
                        buf[index++] = 'r';
                        i += 3;
                    }
                    else if (str[i + 3] == '.' && end_of_letter(str, i + 3)) {
                        buf[index++] = 'l';
                        i += 4;
                    }
                    else print_error();
                }
                else if (str[i + 2] == '-') {
                    if (end_of_letter(str, i + 2)) {
                        buf[index++] = 'w';
                        i += 3;
                    }    
                    else if (str[i + 3] == '.' && end_of_letter(str, i + 3)) {
                        buf[index++] = 'p';
                        i += 4;
                    }
                    else if (str[i + 3] == '-' && end_of_letter(str, i + 3)) {
                        buf[index++] = 'j';
                        i += 4;
                    }
                    else print_error();
                }
            }
        }
        else if (str[i] == '-') {
            if (end_of_letter(str, i)) {
                buf[index++] = 't';
                i++;
            }
            else if (str[i + 1] == '.') {
                if (end_of_letter(str, i + 1)) {
                    buf[index++] = 'n';
                    i += 2;
                }
                else if (str[i + 2] == '.') {
                    if (end_of_letter(str, i + 2)) {
                        buf[index++] = 'd';
                        i += 3;
                    }
                    else if (str[i + 3] == '.' && end_of_letter(str, i + 3)) {
                        buf[index++] = 'b';
                        i += 4;
                    }
                    else if (str[i + 3] == '-' && end_of_letter(str, i + 3)) {
                        buf[index++] = 'x';
                        i += 4;
                    } 
                    else print_error();
                }
                else if (str[i + 2] == '-') {
                    if (end_of_letter(str, i + 2)) {
                        buf[index++] = 'k';
                        i += 3;
                    }
                    else if (str[i + 3] == '.' && end_of_letter(str, i + 3)) {
                        buf[index++] = 'c';
                        i += 4;
                    }
                    else if (str[i + 3] == '-' && end_of_letter(str, i + 3)) {
                        buf[index++] = 'y';
                        i += 4;
                    }
                    else print_error();
                }
            }
            else if (str[i + 1] == '-') {
                if (end_of_letter(str, i + 1)) {
                    buf[index++] = 'm';
                    i += 2;
                }
                else if (str[i + 2] == '.') {
                    if (end_of_letter(str, i + 2)) {
                        buf[index++] = 'g';
                        i += 3;
                    }
                    else if (str[i + 3] == '.' && end_of_letter(str, i + 3)) {
                        buf[index++] = 'z';
                        i += 4;
                    }
                    else if (str[i + 3] == '-' && end_of_letter(str, i + 4)) {
                        buf[index++] = 'q';
                        i += 4;
                    }
                    else print_error(); 
                }
                else if (str[i + 2] == '-' && end_of_letter(str, i + 2)) {
                    
                    buf[index++] = 'o';
                    i += 3;
                }
                else print_error();
            }
        }
        else if (str[i] == ' ') {
            if (str[i + 1] == ' ' && str[i + 2] == ' ' && str[i + 3] == ' ' && str[i + 4] == ' ' 
                                                       && str[i + 5] == ' ' && str[i + 6] == ' ') {
                buf[index++] = ' ';
                i += 7;
            }
            else i++;
        }
        else if (str[i] == '\n') i++;
        else if (str[i] == '\\' && str[i + 1] == 'n') i += 2;
    }
    write(1, buf, index);
    mx_printchar('\n');
}
