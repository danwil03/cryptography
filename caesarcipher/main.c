#include <stdio.h>

#define ASCII_UPPERCASE_A 65
#define ASCII_UPPERCASE_Z 90
#define ASCII_LOWERCASE_A 97
#define ASCII_LOWERCASE_Z 122

void encrypt(char *input, int len, int key) {
    for(int i=0; i<len; i++) {
        int currentkey = key;
        while(currentkey != 0) {
            if(input[i] == ASCII_UPPERCASE_Z) input[i] = ASCII_UPPERCASE_A;
            else if(input[i] == ASCII_LOWERCASE_Z) input[i] = ASCII_LOWERCASE_A;
            else input[i] += 1;
            currentkey -= 1;
        }
    }
}

void decrypt(char *input, int len, int key) {
    for(int i=0; i<len; i++) {
        int currentkey = key;
        while(currentkey != 0) {
            if(input[i] == ASCII_UPPERCASE_A) input[i] = ASCII_UPPERCASE_Z;
            else if(input[i] == ASCII_LOWERCASE_A) input[i] = ASCII_LOWERCASE_Z;
            else input[i] -= 1;
            currentkey -= 1;
        }
    }
}

int main() {
    char text[6] = "XYZxyz";
    printf("Before encryption: %s\n", text);
    encrypt(text, 6, 3);
    printf("After encryption: %s\n", text);
    decrypt(text, 6, 3);
    printf("After encryption: %s\n", text);

    return 0;
}
