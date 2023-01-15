#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>


int main(void) {

    // store the entered key from the CLI
    string key = "zyxwvutsrqponmlkjihgfedcbz";
    printf("%s\n", key);

    // store the string length of the key
    int keylength = strlen(key);

    // create a character array of size equal to 'key'
    char key_modified[keylength + 1];

    // convert key to UPPERCASE
    for (int i = 0; i < keylength; i++) {
        key_modified[i] = toupper(key[i]);
        printf("%c", key_modified[i]);
    }
    printf("\n");

    // check for unique characters
    for (int i = 0; i < (keylength - 1); i++) {

        // initiate staggered counter
        for (int j = (i + 1); j < keylength; j++) {

            // if 'char i' matches 'char i + 1'
            if (key_modified[i] == key_modified[j]) {

                // key check failed
                printf("Key is not unique.\n");
                return 1;
            }
        }
    }
    printf("Key is unique!\n");
}
