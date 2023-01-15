#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>


int main(void) {

    // store the entered key from the CLI
    string key = "zyxwvutsrqponmlkjihgfedcba";
    printf("%s\n", key);

    // store the string length of the key
    int keylength = strlen(key);

    // create an array of size equal to 'key'
    char key_modified[keylength];

    // convert key to UPPERCASE
    for (int i = 0; i < keylength; i++) {
        key_modified[i] = toupper(key[i]);
    }
    printf("%s\n", key);

    // check for unique characters
    for (int i = 0; i < (keylength - 1); i++) {

        // initiate staggered counter
        for (int j = (i + 1); j < keylength; j++) {

            // if 'char i' matches 'char i + 1'
            if (key[i] == key[j]) {

                // key check failed
                printf("Key is not unique.\n");
            }
        }
    }
    printf("Key is unique!\n");
}
