#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// introduce prototype functions
bool check_valid(string key);
string text_conversion(string plaintext, string key, string ciphertext);



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

    // prompt user for plaintext
    string plaintext = get_string("Plain text: ");

    // initialise an array for the text_conversion function to store the ciphertext
    int arraylength = strlen(plaintext);
    char ciphertext[arraylength + 1];

    // convert plaintext to ciphertext
    string ciphertext = text_conversion(plaintext, key, ciphertext);


// ERROR HERE - array decay - local array declared inside function text_conversion ceases to exist once the function returns.
// need to find a way to combat this!


    // print ciphertext
    printf("Cipher text: %s\n", ciphertext);
    free(ciphertext);
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





string text_conversion(string plaintext, string key, string ciphertext) {

    // length of plaintext
    int arraylength = strlen(plaintext);

    // create a character array of size equal to 'plaintext' to store the ciphered text, plus NULL value
    //char ciphertext[arraylength + 1] = malloc(sizeof(ciphertext));

    // allocate dynamic memory for the ciphertext array


    // convert plaintext to ciphertext
    for (int i = 0; i < arraylength; i++) {

        // if plaintext[i] is lowercase (want to convert value to 0-25 for alphabet position)
        if (islower(plaintext[i])) {

            // store modified plaintext in a temporary value
            int temp = plaintext[i] - 97;

            // write ciphertext as (key * plaintext)
            ciphertext[i] = key[temp];

            // need to keep ciphertext in same case as plaintext (key may be given in uppercase)
            if (isupper(ciphertext[i])) {
                ciphertext[i] += 32;
            }
        }

        // if plaintext[i] is uppercase (want to convert value to 0-25 for alphabet position)
        if (isupper(plaintext[i])) {

            // store plaintext in a temporary value
            int temp = plaintext[i] - 65;

            // write ciphertext as (key * plaintext)
            ciphertext[i] = key[temp];

            // need to keep ciphertext in same case as plaintext (key may be given in lowercase)
            if (islower(ciphertext[i])) {
                ciphertext[i] -= 32;
            }
        }
    }
    ciphertext[arraylength] = '\0';
    return ciphertext;
}



