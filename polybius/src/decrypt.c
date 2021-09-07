// Description

// welcome to ancient greece. the next cipher was made by an ancient greek historian and scholar polybius.
// to decrypt the secret message, your square will have the dimensions six by six. after you have added 
// all the letters, add the digits from zero to nine. that should make a perfect square for you. 
// on the sides, use the letters a, b, c, d, e, and f.binary for this task must be called polybius.

#include "polybius.h"

static bool is_lower_case(char c) {
    return (c > 96 && c < 123);
}

void decrypt(char *str) {
    char polybius_square[7][7];
    int i, j, shift = 0;
    char *output = mx_strnew(mx_strlen(str));
    int row, column;

    for (i = 0; i < 7; i++) 
        for (j = 0; j < 7; j++)
            polybius_square[i][j] = '\0';
    for (i = 0, j = 1; j < 7; j++)
        polybius_square[i][j] = 'a' + j - 1;
    for (j = 0, i = 1; i < 7; i++) 
        polybius_square[i][j] = 'a' + i - 1;
    for (i = 1; i < 7; i++) {
        for (j = 1; j < 7 && polybius_square[i][j] != 'z'; j++) {
            if (shift >= 26)
                polybius_square[i][j] = '0' + shift - 26;
            else
                polybius_square[i][j] = 'a' + shift;
            shift++;
        }
    }  
    for (i = 0; i < mx_strlen(str);) {
        if (mx_isalpha(str[i]) && mx_isalpha(str[i + 1])) {
            row = str[i] - 'A' + 1 - 32 * (is_lower_case(str[i]));
            column = str[i + 1] - 'A' + 1 - 32 * (is_lower_case(str[i]));
            output[i] = polybius_square[row][column];
            i += 2;   
        }
        else {
            output[i] = str[i]; 
            i++;
        }
    }
    write(1, output, mx_strlen(str));
    mx_printchar('\n');
    mx_strdel(&output);
}
