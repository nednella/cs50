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



    // iterate through the key 1 character at a time
    for (int i = 0; i < keylength; i++) {

        // check for non-alphabetic characters, terminate program if true
        if (isalpha(key[i]) == 0) {
            printf("The key must contain alphabetic characters only.\n");
            return 1;
        }

        // check for non-unique characters, terminate program if true
        for (int j = 0; i < keylength; j++) {
            if (key[i] == key[j]) {
                printf("The key must cotain unique characters only.\n");
                return 1;
            }
        }



    }
    // check for strict key length of 26 characters
    //if (keylength != 26 && ) {
        //printf("Key must contain 26 characters.");
    //}




}