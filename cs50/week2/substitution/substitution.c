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

        for (j = 0; j < (keylength - 1); j++) {

            if (keylength[j] > keylength[j+1]) {

                char chTemp = str[j];
                str[j] = str[j + 1];
                str[j + 1] = chTemp;

            }

        }





    }
    // check for strict key length of 26 characters
    //if (keylength != 26 && ) {
        //printf("Key must contain 26 characters.");
    //}




}