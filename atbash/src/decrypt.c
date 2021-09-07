// Description
 
// hello again the one.the next cipher uses a reverse alphabet.
// the cipher is a substitution cipher with a specific key where the order of the
// alphabet is reversed.ie all a are replaced with z.all b are replaced with y.
// and so on.it was originally used for the hebrewalphabet but
// can be used for any alphabet.binary for the next task must be named atbash.
// and it has the same error handling rules except binary name.
// the knowledge of this cipher helped the heroes of the movie da vinci code with robert 
// langdon and sophie neve and lee teabing.when they figured out the meaning of the poetic line.
// atbash will reveal the truth like a ray.according to the plot it turns out that using the cipher 
// the word baphomet was encrypted.it helped to guess the word sofia.this is no coincidence as the 
// heroine of dan browns novel is called sophie neve.
 
#include "atbash.h"

static bool is_upper_case(char c) {
    return (c > 64 && c < 91);
}

static bool is_lower_case(char c) {
    return (c > 96 && c < 123);
}

void decrypt(char *str) {
    char alphabet[26] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 
                         'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};
    char ALPHABET[26] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 
                         'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};
    char *output = mx_strnew(mx_strlen(str));
    int i = 0, k;

    for (int j = 0; j < mx_strlen(str); j++)
        output[j] = '\0';
    while (i < mx_strlen(str)) {
        if (mx_isalpha(str[i])) {
            if (is_upper_case(str[i])) {
                k = 25 - (str[i] - 65);
                output[i++] = ALPHABET[k];
            }
            else if (is_lower_case(str[i])) {
                k = 25 - (str[i] - 97);
                output[i++] = alphabet[k];
            }
        }
        else {
            output[i] = str[i];
            i++;
        }
    }
    write(1, output, mx_strlen(output));
    mx_printchar('\n');
    free(output);
    output = NULL;
}
