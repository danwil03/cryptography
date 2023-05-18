#include <stdio.h>

#define ASCII_UPPERCASE_A 65
#define ASCII_UPPERCASE_Z 90
#define ASCII_LOWERCASE_A 97
#define ASCII_LOWERCASE_Z 122

void encrypt(char *input, int len, char *key, int keylen) {
    int keys[keylen];
    for(int i=0; i<keylen; i++) {
        if(key[i] >= ASCII_UPPERCASE_A && key[i] <= ASCII_UPPERCASE_Z) {
            keys[i] = key[i] - ASCII_UPPERCASE_A;
        } else if(key[i] >= ASCII_LOWERCASE_A && key[i] <= ASCII_LOWERCASE_Z) {
            keys[i] = key[i] - ASCII_LOWERCASE_A;
        }
    }

    for(int i=0; i<len; i++) {
        int current = keys[i % keylen];
        while(current != 0) {
            if(input[i] == ASCII_UPPERCASE_Z) {
                input[i] = ASCII_UPPERCASE_A;
            }else if(input[i] == ASCII_LOWERCASE_Z) {
                input[i] = ASCII_LOWERCASE_A;
            }else{
                input[i] += 1;
            }
            current -= 1;
        }
    }
}

int main() {
    char text[6] = "CRYPTO";
    char key[3] = "DUH";
    printf("Before encryption: %s\n", text);
    encrypt(text, 6, key, 3);
    printf("After encryption: %s\n", text);

    return 0;
}
