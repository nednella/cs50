#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>


	int main(void) {

        // store the entered key from the CLI
        string key = "zyxwvutsrqponmlkjihgfedcba";

        // store the string length of the key
        int keylength = strlen(key);





        // iterate through the key 1 character at a time
        for (int i = 0; i < keylength; i++) {

            // check for non-alphabetic characters, terminate program if true
            if (isalpha(key[i]) == 0) {
                printf("The key must contain alphabetic characters only.\n");
                return 1;
            }

            // bubble sort the key in ascdending order
            for (j = 0; j < (keylength - 1); j++) {

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
