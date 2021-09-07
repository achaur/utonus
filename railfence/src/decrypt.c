// Descrption

// the next cipher is completely off the rails!
// when you write out the solution,
// it looks like a wave or a zigzag.
// these types of ciphers are usually called
// transposition ciphers.
// it is not strong, but definitely fun.
// to solve this cipher you will need the
// number key 4.
// consider spaces, commas, periods, and other
// punctuation also as characters.
// binary for this task must be called "railfence".
// and as always, the program has to have the same
// error handling rules as the previous ones
// except the binary name.

#include "railfence.h"

void decrypt(char *str, int n) {
    int len = mx_strlen(str);
    char table[n][len];
    char *output = mx_strnew(mx_strlen(str));
    bool down = false;
    int row = 0, index = 0;

    for (int i = 0; i < n; i++)
        for (int j = 0; j < len; j++)
            table[i][j] = '\0';
    for (int column = 0; column < len; column++) {
        if (row == n - 1) down = true;
        if (row == 0) down = false;
        table[row][column] = '*';
        row += 1 - 2 * down;
    }
    row = 0;
    for (row = 0; row < n; row++)
        for (int column = 0; column < len; column++)
            if (table[row][column] == '*' && str[index])
                table[row][column] = str[index++];
    index = 0;
    for (int column = 0; column < len; column++) 
        for (int row = 0; row < n; row++) 
            if (table[row][column] != '\0' && str[index])
                output[index++] = table[row][column];
  
    write(1, output, mx_strlen(output));
    mx_strdel(&output);
    mx_printchar('\n');
}
