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

    printf("Key before sorting: %s", key);
    printf("\n");

    //printf("First character: %c\n", key[0]);
    //printf("First character: %c\n", key[1]);

    // bubble sort key ascending order
    for (int i = 0; i < keylength; i++) {

        for (int j = 0; j < (keylength - 1); j++) {

            if (key[j] > key[j+1]) {
                char ChTemp = key[j];
                key[j] = key[j + 1];
                key[j + 1] = ChTemp;
            }
        }
    }
    printf("Key after sorting: %s\n", key);
}
