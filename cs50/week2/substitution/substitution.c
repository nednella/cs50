#include <cs50.h>
#include <stdio.h>
#include <ctype.h>

int main(int argc, string argv[]) {

    // if the command-line argument is not equal to 2 elements
    if (argc != 2) {
        // print a guide for correct usage
        printf("Usage: ./substitution [key]");
        // and terminate program
        return 1;
    }

    // store the entered key from the CLI
    string key = atoi(argv[1]);

    // store the character length of the key
    int keylength = strlen(key);

    // check the contents of the key (for non-alphabetic characters)
    for (int i = 0; i < keylength; i++) {

        printf("%c\n",key[i])

        if (isalpha(key[i])) {
            


        }



    }

    if (keylength != 26 && ) {
        printf("Key must contain 26 characters.");
    }






}