// Task description

// Do you play checkers? The next cipher is all about a checkerboard. 
// This is a rather old cipher, developed back in the sixteenth century. 
// It was also used during the Spanish Civil War to protect radio transmissions. 
// Later on, this cipher got incorporated into other, more advanced ones, 
// like the VIC cipher and used by Soviet spies.
// To decrypt this cipher,  you will need three keys. First is a rearranged alphabet   
// “csvl.myrpgudxk iahzojtqenbwf”. Pay attention that this alphabet  also includes 
// a dot and a space character, making it a twenty eight letter alphabet. 
// Second and third keys are numbers three and eight. There are not going to be any  
// digits in the secret message and test cases, so you don't have to worry about that.
// Assume digits are forbidden in plain text for this cipher. 
// Binary for this task must be called "checkboard". 
// And in case of any errors your program must print 
// "usage: ./checkboard "text" "alphabet" "num1" "num2"" to the standard error stream.

#include "checkboard.h"

void decrypt(char *text, char *alpha, int key1, int key2) {
    char table[4][11];
    int i = 0, index = 0, row, column;
    char *output = mx_strnew(mx_strlen(text));

    for (int i  = 0; i < 4; i++) 
        for (int j = 0; j < 11; j++)
            table[i][j] = '-';
    for (int j = 1; j < 11; j++)
        table[i][j] = j - 1 + '0';
    table[2][0] = key1 + '0';     
    table[3][0] = key2 + '0';
    for (int i = 1; i < 4; i++)
        for (int j = 1; j < 11 && alpha[index]; j++)
            if (!(i == 1 && j == key1 + 1))
                if (!(i == 1 && j == key2 + 1))
                    table[i][j] = alpha[index++];      
    for (int i = 0, index = 0; i < mx_strlen(text); i++) {
        if (mx_isdigit(text[i])) {
            if (((text[i] - '0') != key1) && ((text[i] - '0') != key2)) {
                row = 1;
                column = text[i] - '0' + 1;
                output[index++] = table[row][column];
            }
            else {
                if (text[i + 1]) {
                    if (text[i] - '0' == key1) {
                        row = 2;
                        column = text[i + 1] - '0' + 1;
                        output[index++] = table[row][column];

                    }
                    else if (text[i] - '0' == key2) {
                        row = 3;
                        column = text[i + 1] - '0' + 1;
                        output[index++] = table[row][column];
                    }
                    i++;
                }
            }
        }
        else 
            output[index++] = text[i];
    }
    write(1, output, mx_strlen(output));
    mx_printchar('\n');
    mx_strdel(&output);
}
