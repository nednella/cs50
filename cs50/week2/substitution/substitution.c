#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

bool unique_key(string key, int keylength);

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
    //if (keylength != 26) {
        //printf("Key must contain 26 characters.");
        // terminate the program if true
        //return 1;
    //}

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
        printf("Key is not comprised of unique characters.");
    }


}





bool unique_key(string key, int keylength) {

    // create a character array of size equal to 'key'
    char modified_key[keylength];

    // convert key to UPPERCASE and fill in new array
    for (int i = 0; i < keylength; i++) {
        modified_key[i] = toupper(key[i]);
        printf("%c", modified_key[i]);
    }
    printf("\n");

    // check for unique characters
    for (int i = 0; i < (keylength - 1); i++) {

        // initiate staggered counter
        for (int j = (i + 1); j < keylength; j++) {

            // if 'char i' matches 'char i + 1'
            if (modified_key[i] == modified_key[j]) {

                // key check failed
                printf("Key is not unique.\n");
                return false;
            }
        }
    }
    printf("Key is unique!\n");
    return true;
}