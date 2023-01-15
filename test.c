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

    printf("First character: %c\n", key[0]);
    printf("First character: %c\n", key[1]);

    // bubble sort key ascending order
    //for (int i = 0; i < (keylength - 1); i++) {
        //for (int j = (i + 1); j < keylength; j++) {
            //if (key[i] > key[j]) {
                //char ChTemp = key[i];
                //key[i] = key[j];
                //key[j] = ChTemp;
            //}
        //}
    //}
    printf("Key after sorting: %s", key);
}
