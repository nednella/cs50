#include <cs50.h>
#include <stdio.h>
#include <string.h>

// values for colors and score (EXACT == right letter, right place; CLOSE == right letter, wrong place; WRONG == wrong letter)
#define EXACT 2
#define CLOSE 1
#define WRONG 0

// ANSI color codes for boxed in letters
#define GREEN   "\e[38;2;255;255;255;1m\e[48;2;106;170;100;1m"
#define YELLOW  "\e[38;2;255;255;255;1m\e[48;2;201;180;88;1m"
#define RED     "\e[38;2;255;255;255;1m\e[48;2;220;20;60;1m"
#define RESET   "\e[0;39m"



int main(void) {

    // guess word
    string guess = "games";

    // string length of guess word
    int guesslength = strlen(guess);

    // create array of a size equal to the length of the guess word
    int status[guesslength];

    // set all values inside the array.... equal to 0
    //for (int i = 0; i < guesslength; i++) {
        //status[i] = 2;
        //printf("%i", status[i]);
    //}
    status[0] = 0;
    status[1] = 1;
    status[2] = 2;
    status[3] = 1;
    status[4] = 0;

    printf("\n");

    // print the guess word, 1 char at a time
    for (int j = 0; j < guesslength; j++) {

        if (status[j] == 2) {
            printf(GREEN"%c"RESET"", guess[j]);
        }

        if (status[j] == 1) {
            printf(YELLOW"%c"RESET"", guess[j]);
        }

        if (status[j] == 0) {
            printf(RED"%c"RESET"", guess[j]);
        }
    }
    printf("\n");



}

