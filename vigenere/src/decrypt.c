// Description

// For several centuries, this cipher resisted all attempts to break it and earned
// the nickname - the indecipherable cipher.
// The cipher consists of a sequence of several Caesar ciphers with different shift values.
// An alphabet table called "tabula recta" or a special square table can be used for encryption.
// Writer Jules Verne used the cipher to encrypt the document in his novel La Jangada.
// Things are getting harder, aren't they? Binary must be named vigenere.
// And your program must take two arguments: a string to decode and a key.
// Your program must print usage: ./vigenere "str" "key" on the standard error stream
// in case of any errors.
// To decrypt the next cipher, use the keyword "brain".

#include "vigenere.h"

static bool is_upper_case(char c) {
    return (c > 64 && c < 91);
}
#include <stdio.h>
void decrypt(char *str, char *key) {
    char alphabet[26] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 
                         'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};
    char vigenere_table[26][26];
    int shift = 0, k, column, index = 0;
    char *output = mx_strnew(mx_strlen(str));

    for (int i = 0; i < 26; i++)
        for (int j = 0; j < 26; j++)
            vigenere_table[i][j] = '\0';
    for (int i = 0; i < 26; i++) {
        for (int j = 0; j < 26; j++) {
            k = j + shift - 26 * ((j + shift) > 25);
            vigenere_table[i][j] = alphabet[k];
        }
        shift++;
    }
    for (int i = 0; i < 26; i++) {
        for (int j = 0; j < 26; j++)
            printf("%c ", vigenere_table[i][j]);
        printf("\n");
    }
    for (int i = 0; i < mx_strlen(key); i++)
        if (is_upper_case(key[i]))
            key[i] += 32;
    for (int i = 0; i < mx_strlen(str); i++) {
        if (mx_isalpha(str[i])) {
            column = 0;
            if (is_upper_case(str[i]))
                    while(vigenere_table[column][key[index] - 'a'] != str[i] + 32) {
                    printf("index = %d, column = %d\n", index, column);
                    column++;
                }
            else {
                printf("index = %d, column = %d\n", index, column);
                while(vigenere_table[column][key[index] - 'a'] != str[i]) {
                    column++;
                }
            }
                
            output[i] = alphabet[column] - 32 * (is_upper_case(str[i]));
            index++;
            index = index % mx_strlen(key);
        }
        else 
            output[i] = str[i];
    }
    write(1, output, mx_strlen(output));
    mx_printchar('\n');
    mx_strdel(&output);
}
