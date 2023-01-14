#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

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

    // check for an invalid key



    // store the string length of the key
    int keylength = strlen(key);



    // check the contents of the key (for non-alphabetic characters)
    for (int i = 0; i < keylength; i++) {

        if (isalpha(key[i]) == 0) {
            printf("The key must contain alphabetic characters only.\n");
            return 1;
        }



    }
    // check for strict key length of 26 characters
    //if (keylength != 26 && ) {
        //printf("Key must contain 26 characters.");
    //}




}