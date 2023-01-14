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
        string guess = "pence";
        int score[] = {0, 0, 0, 0, 0};
        // should be scored: 0, 1, 2, 2, 2

        // compare guess to choice and score points as appropriate, scoring points

        // store string length of guess and choice words, for iteration
        int guesslength = strlen(guess);
        int choicelength = strlen(choice);

        // iterate through the guess 1 letter at a time to score points
        for (int i = 0; i < guesslength; i++) {

            printf("%c", guess[i]);
            printf("%c\n", choice[i]);

            // if the guess letter matches the choice letter, assign 2 (EXACT value)
            if (guess[i] == choice[i]) {
                printf("2!\n");
                score[i] = 2;
            }

            // if the guess letter didn't match the choice letter, check to see if it matches any chars in the choice word and assign 1
            if (guess[i] != choice[i]) {

                printf("%c\n", guess[i]);

                for (int j = 0; j < choicelength; j++) {
                    printf("%c", choice[j]);

                    if (guess[i] == choice[j]) {
                        score[i] = 1;
                        printf("1!\n");
                        break;
                    }

                }
                printf("\n");

            }
            printf("\n");
        }

        for (int z = 0; z < sizeof(score)/sizeof(score[0]); z++) {
            printf("%i ",score[z]);
        }
        printf("\n");
    }
