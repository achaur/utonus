// Description

// Who wants some bacon? The next cipher was created by Francis Bacon, 
// and it has a rather different approach to encrypting a message. 
// The secret message is hidden not in the content of the text, 
// but rather in the presentation. The cipher text itself does no t mean anything, 
// you only want to know whether the letters are uppercase or lowercase.
// If a letter is uppercase, it is the letter B, and if lowercase, then it is the letter A. 
// Characters in the text that are not letters are ignored.
// Every five letters form a code. And every code translates to a character from
// your alphabet. You will not need any key for this.
// However, you should know that the alphabet you will need has unique codes
// for every letter.
// Careful, because there are two types of Baconian alphabet tables, you need the one
// where i and j have two different codes. To spice things up, we have added some
// more symbols to the standard Baconian alphabet. After z, there is a code for a
// space (“ ”) - BBABA, a period (“.”) - BBABB, and a comma (“,”) - BBBAA.
// The characters that don’t have a code are ignored.
// Binary for this task must be called "baconian".

#include "baconian.h"

static bool is_lower_case(char c) {
    return (c > 96 && c < 123);
}

void decrypt(char *str) {
    char alphabet[29] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 
                         'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z', ' ', '.', ','};
    char *baconian_alphabet[29] = {"AAAAA", "AAAAB", "AAABA", "AAABB", "AABAA", "AABAB", "AABBA", "AABBB", 
                                   "ABAAA", "ABAAB", "ABABA", "ABABB", "ABBAA", "ABBAB", "ABBBA", "ABBBB", 
                                   "BAAAA", "BAAAB", "BAABA", "BAABB", "BABAA", "BABAB", "BABBA", "BABBB", 
                                   "BBAAA", "BBAAB", "BBABA", "BBABB", "BBBAA"};
    char *baconian = mx_strnew(mx_strlen(str));
    int k = 0, index = 0;
    char *output = mx_strnew(mx_strlen(str));
    char buf[6];

    for (int i = 0; i < mx_strlen(str); i++) {
        if (mx_isalpha(str[i])) {
            if (is_lower_case(str[i]))
                baconian[k++] = 'A';
            else 
                baconian[k++] = 'B';
        }
    }
    for (int i = 0; baconian[i] != '\0';) {
        for (int j = 0; j < 6; j++)
            buf[j] = '\0';
        for (int j = 0; j < 5; j++)
            buf[j] = baconian[i++];
        for (int j = 0; j < 29; j++)
            if (mx_strcmp(buf, baconian_alphabet[j]) == 0)
                output[index++] = alphabet[j];
    }
    write(1, output, mx_strlen(output));
    mx_printchar('\n');
    mx_strdel(&output);
    mx_strdel(&baconian);
}
