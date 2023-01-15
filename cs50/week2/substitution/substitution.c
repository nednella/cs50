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

    // store the string length of the key
    int keylength = strlen(key);

    // check for an invalid key
    // check for strict key length of 26 characters
    if (keylength != 26) {
        printf("Key must contain 26 characters.");
    }

    // check for non-alphabetic characters

    // print key before sorting
    printf("Key before sorting: %s", key);

    // sort key in ascending order & check for non-alphabetic characters
    // insert function here

}



string key_sort(string key, int keylength) {


    // iterate through key 1 char at a time
    for (int i = 0; i < keylength; i++) {



        // check for non-alphabetic characters, terminate program if true
        if (isalpha(key[i]) == 0) {
            printf("The key must contain alphabetic characters only.\n");
            return 1;
        }



        // bubble sort the key in ascdending order
        for (j = (i + 1); j < keylength; j++) {

            // compare 'char i' to 'char i + 1', if greater
            if (key[j] > key[j+1]) {

                // store 'char i' temporarily
                char chTemp = key[j];
                key[j] = key[j + 1];
                key[j + 1] = chTemp;

            }

        }





    }




}