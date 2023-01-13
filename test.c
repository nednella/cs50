	#include <cs50.h>
	#include <stdio.h>
    #include <string.h>

	int main(void) {

    int wordsize = 5;
    string guess = "";
    int correctlength = false;

        while (correctlength == false) {
            guess = get_string("Guess: ");

            int guesslength = strlen(guess);

            if (guesslength == wordsize) {
                correctlength = true;
            }
        }
        printf("Success\n");
    }