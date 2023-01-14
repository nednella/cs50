#include <cs50.h>
#include <stdio.h>
#include <string.h>




int main(void) {

    // guess word
    string guess = "games";

    // string length of guess word
    int guesslength = strlen(guess);

    // create array of a size equal to the length of the guess word
    int status[guesslength];

    // set all values inside the array equal to 0
    for (int i = 0; i < guesslength; i++) {
        status[i] = 0;
        printf("%i", status[i]);
    }
    printf("\n");

    // print the guess word, 1 char at a time
    for (int j = 0; j < guesslength; j++) {
        printf("%c", guess[j]);
    }
    printf("\n");






}


