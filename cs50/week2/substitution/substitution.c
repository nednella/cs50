#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

bool unique_key(string key);

int main(int argc, string argv[]) {

    // if the command-line argument is not equal to 2 elements
    if (argc != 2) {
        // print a guide for correct usage
        printf("Usage: ./substitution [key]\n");
        // and terminate program
        return 1;
    }

    // store the entered key from the CLI
    string key = argv[1];

    // store key string length
    int keylength = strlen(key);

    // check for strict key length of 26 characters
    if (keylength != 26) {
        printf("Key must contain 26 characters.");
        // terminate the program if true
        return 1;
    }

    // check for non-alphabetic characters
    for (int i = 0; i < keylength; i++) {

        // terminate program if true
        if (!isalpha(key[i])) {
            printf("The key must contain alphabetic characters only.\n");
            return 1;
        }
    }

    // check for a unique key
    if (unique_key(key) == false) {
        printf("Key must contain 26 characters.");
    }


}





bool unique_key(string key) {

    // store key string length
    int keylength = strlen(key);

    // convert key to UPPERCASE
    for (int i = 0; i < keylength; i++) {
        key[i] = toupper(key[i]);
    }

    // check for unique characters
    for (int i = 0; i < (keylength - 1); i++) {

        // initiate staggered counter
        for (int j = (i + 1); j < keylength; j++) {

            // if 'char i' matches 'char i + 1'
            if (key[i] == key[j]) {

                // key check failed
                return false;
            }
        }
    }
    return true;
}