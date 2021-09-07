#include "vigenere.h"

bool mx_isalpha(int c) {
    return (( c > 64 && c < 91 ) || ( c > 96 && c < 123 )) ? 1 : 0;
}

char *mx_strnew(const int size) {
    char *new = NULL;

    if (size < 0)
        return NULL;
    new = (char *)malloc(sizeof(char) * (size + 1));
    for (int i = 0; i <= size; i++)
        new[i] = '\0';
    return new;
}

int mx_strlen(const char *s) {
    int count = 0;

    for (int i = 0; s[i] != '\0'; i++)
        count++; 
    return count;   
}

void mx_printchar(char c) {
    write(1, &c, 1);
}

bool mx_isspace(char c) {
    if ((c > 8 && c < 14) || c == 32) return 1;
    else return 0;
}

bool mx_isdigit(char c) {
    return (c > 47 && c < 58);
}

int mx_atoi(char *str) {
    int result = 0;
    int sign = 1;

    if (str == NULL) return -1;
    while(mx_isspace(*str))
        str++;
    if (*str == '+' || *str == '-') {
        sign = 1 - 2 * (*str == '-');
        str++;
    }

    while (mx_isdigit(*str)) {
        if (result > 2147483647 / 10 || (result == 2147483647 / 10 && *str++ - 48 > 7)) {
            if (sign)
                return 2147483647;
            else 
                return -2147483648; 
        }
        result = result * 10 + *str - 48;
        str++;
    }  
    return result * sign;
}

void mx_strdel(char **str) { 
    free (*str);
    *str = NULL;
}
