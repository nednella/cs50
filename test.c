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

        string choice = "since";
        string guess = "hello";
        // should be scored: 0, 1, 0, 0, 0

        // compare guess to choice and score points as appropriate, storing points in status
        // store string length of guess and choice words, for iteration
        int guesslength = strlen(guess);
        int choicelength = strlen(choice);

        // iterate through the guess 1 letter at a time to score points
        for (int i = 0; i < guesslength; i++) {

            //printf("%c\n", guess[i]);

            for (int j = 0; j < choicelength; j++) {

                //printf("%c", choice[j]);

                if (guess[i])




            }
            printf("\n");
        }


        // HINTS
        // iterate over each letter of the guess
            // iterate over each letter of the choice
                // compare the current guess letter to the current choice letter
                    // if they're the same position in the word, score EXACT points (green) and break so you don't compare that letter further
                    // if it's in the word, but not the right spot, score CLOSE point (yellow)
            // keep track of the total score by adding each individual letter's score from above





    }