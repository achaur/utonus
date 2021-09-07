#include "morse.h"

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

int mx_strcmp(const char *s1, const char *s2) {
    for (; *s1 == *s2 && (*s1 != '\0' && *s2 != '\0');s1++ && s2++);
    return *s1 - *s2;
}
