// Description
 
// the cipher is named for the roman commander guy julius caesar, 
// who used it for secret correspondence with his generals.
// the cipher belongs to the group of so-called single-alphabetical wildcard ciphers.
// when using the ciphers of this group, each character of the plaintext is replaced 
// by a certain character fixed in this key of the same alphabet.
// key selection methods may vary. the key in caesar's cipher is an arbitrary number 'k',
// selected in the range from one to twenty-five. each letter of the plaintext 
// is replaced by a letter that is 'k' characters further than it is in the alphabet.
// For example, let the key be three. Then the letter A of the English alphabet 
// will be replaced by the letter D, the letter B by the letter E, and so on. 
// Use this cipher with a shift of three, like Julius Caesar when writing military messages. 
// Don't forget about binary. It must be named caesar. And the current program has to have the
// same error handling rules with the text "usage: ./caesar "str" "key" "
// Also, here is a first verse of the LITTLE BIG song Faradenza: Denza Faradenza La bokka 
// de la cokka Grande love-ua and ribaua villa vida loca Gusto rico dante Pereto presto 
// power Karma denza purra kawa konnichiwa-ua
// Good luck!
 
#include "caesar.h" 

static bool is_upper_case(char c) {
    return (c > 64 && c < 91);
}

static bool is_lower_case(char c) {
    return (c > 96 && c < 123);
}

void decrypt(char *str, int shift) {
    char alphabet[26] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 
                         'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};
    char ALPHABET[26] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 
                         'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};
    int k;
    char *output = mx_strnew(mx_strlen(str));

    for (int i = 0; i < mx_strlen(str); i++) {
        if (mx_isalpha(str[i])) {
            if (is_lower_case(str[i])) {
                k = str[i] - 'a' + shift - 26 * ((str[i] - 'a' + shift) > 25);
                output[i] = alphabet[k];
            }
            else if (is_upper_case(str[i])) {
                k = str[i] - 'A' + shift - 26 * ((str[i] - 'A' + shift) > 25);
                output[i] = ALPHABET[k];
            }
        }
        else 
            output[i] = str[i];
    }
    write(1, output, mx_strlen(str));
    mx_printchar('\n');
    free(output);
    output = NULL;
}
