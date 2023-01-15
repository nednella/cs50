#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

bool check_valid(string key);

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

    // check for a valid key
    if (check_valid(key) == false) {

        // if false, terminate program
        printf("Terminating program.\n");
        return 1;
    }

    // prompt user for plain text
    string plaintext = get_string("Plain text: ");




    // move this all into a function


    // length of plaintext
    int arraylength = strlen(plaintext);

    // create an index array of size equal to 'plaintext' to store alphabetical location of plaintext[i]
    char index[arraylength + 1];

    // create a character array of size equal to 'plaintext' to store the ciphered text
    char ciphertext[arraylength + 1];

    // convert plaintext to ciphertext
    for (int i = 0; i < arraylength; i++) {

        // if plaintext[i] is lowercase (want to convert value to 0-25 for alphabet position)
        if (islower(plaintext[i])) {
            index[i] = plaintext[i] -= 97;

            // write ciphertext as (key * plaintext)
            ciphertext[i] = key[index[i]];

            // need to keep ciphertext in same case as plaintext (key may be given in uppercase)
            if (isupper(ciphertext[i])) {
                ciphertext[i] += 32;
            }
        }

        // if plaintext[i] is uppercase (want to convert value to 0-25 for alphabet position)
        if (isupper(plaintext[i])) {
            // convert to an index
            index[i] = plaintext[i] -= 65;

            // write ciphertext as (key * plaintext)
            ciphertext[i] = key[index[i]];

            // need to keep ciphertext in same case as plaintext (key may be given in lowercase)
            if (islower(ciphertext[i])) {
                ciphertext[i] -= 32;
            }
        }

    }








}



bool check_valid(string key) {

    // store key string length
    int keylength = strlen(key);

    // check for strict key length of 26 characters
    //if (keylength != 26) {
        //printf("Key must contain 26 characters.");
        // terminate the program if true
        //return false;
    //}

    // check for non-alphabetic characters
    for (int i = 0; i < keylength; i++) {

        // terminate program if true
        if (!isalpha(key[i])) {
            printf("The key must contain alphabetic characters only.\n");
            return false;
        }
    }

    // create a character array of size equal to 'key' (cannot overwrite the read-only string 'key')
    char modified_key[keylength + 1];

    // convert key to UPPERCASE and fill in new array 1 character at a time
    for (int i = 0; i < keylength; i++) {
        modified_key[i] = toupper(key[i]);
    }

    // check for unique characters
    for (int i = 0; i < (keylength - 1); i++) {

        // initiate staggered counter
        for (int j = (i + 1); j < keylength; j++) {

            // if 'char i' matches 'char i + 1'
            if (modified_key[i] == modified_key[j]) {

                // key check failed
                printf("Key is not comprised of unique characters.\n");
                return false;
            }
        }
    }
    return true;
}