#include <cs50.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>

// each of our text files contains 1000 words
#define LISTSIZE 1000

// values for colors and score (EXACT == right letter, right place; CLOSE == right letter, wrong place; WRONG == wrong letter)
#define EXACT 2
#define CLOSE 1
#define WRONG 0

// ANSI color codes for boxed in letters
#define GREEN   "\e[38;2;255;255;255;1m\e[48;2;106;170;100;1m"
#define YELLOW  "\e[38;2;255;255;255;1m\e[48;2;201;180;88;1m"
#define RED     "\e[38;2;255;255;255;1m\e[48;2;220;20;60;1m"
#define RESET   "\e[0;39m"

// user-defined function prototypes
string get_guess(int wordsize);
int check_word(string guess, int wordsize, int status[], string choice);
void print_word(string guess, int wordsize, int status[]);





int main(int argc, string argv[])
{
    // ensure correct command-line usage
    int wordsize = 0;

    if (argc != 2){
		printf("CORRECT FORMAT: ./wordle [wordsize]\n");
		return 1;
	}

    // ensure argv[1] is either 5, 6, 7, or 8 and store that value in wordsize instead
    int value = atoi(argv[1]);

    // if argv[1] is not 5, 6, 7 or 8,
    if (value != 5 && value != 6 && value != 7 && value != 8) {
        // print an error and,
        printf("ERROR: [wordsize] must be either 5, 6, 7 or 8\n");
        // terminate the program
        return 1;
    }

    // store specified wordsize in the CLI
    wordsize = atoi(argv[1]);

    // open correct file, each file has exactly LISTSIZE words
    char wl_filename[6];
    sprintf(wl_filename, "%i.txt", wordsize);
    FILE *wordlist = fopen(wl_filename, "r");
    if (wordlist == NULL)
    {
        printf("Error opening file %s.\n", wl_filename);
        return 1;
    }

    // load word file into an array of size LISTSIZE
    char options[LISTSIZE][wordsize + 1];

    for (int i = 0; i < LISTSIZE; i++)
    {
        fscanf(wordlist, "%s", options[i]);
    }

    // pseudorandomly select a word for this game
    //srand(time(NULL));
    //string choice = options[rand() % LISTSIZE];

    // pick a word for this game
     string choice = "games";

    // allow one more guess than the length of the word
    int guesses = wordsize + 1;
    bool won = false;

    // print greeting, using ANSI color codes to demonstrate
    printf(GREEN"This is WORDLE50"RESET"\n");
    printf("You have %i tries to guess the %i-letter word I'm thinking of\n", guesses, wordsize);

    // main game loop, one iteration for each guess
    for (int i = 0; i < guesses; i++)
    {
        // obtain user's guess
        string guess = get_guess(wordsize);

        // array to hold guess status, initially set to zero
        int status[wordsize];

        // set all elements of status array initially to 0, aka WRONG
        // use a for loop to loop through each element as the array size itself is a variable, not a constant
        for (int j = 0; j < wordsize; j++) {
            status[j] = 0; // 0 = WRONG LETTER
        }

        // Calculate score for the guess
        int score = check_word(guess, wordsize, status, choice);

        printf("Guess %i: ", i + 1);

        // Print the guess
        print_word(guess, wordsize, status);

        // if they guessed it exactly right, set terminate loop
        if (score == EXACT * wordsize)
        {
            won = true;
            break;
        }
    }

    // Print the game's result
    if (won == true) {
        printf("Congratulations, you won!\n");
    }

    else {
        printf("You did not guess the correct answer, you lost ...\n");
        printf("The correct word was: ", );
    }



    // TODO #7

    // that's all folks!
    return 0;
}





string get_guess(int wordsize)
{
    string guess = "";
    bool correctlength = false;

    // ensure users actually provide a guess that is the correct length

    // while guess is not equal to wordsize
    while (correctlength == false) {

        // prompt user for a guess
        guess = get_string("Input a %i-letter word: ", wordsize);

        // store string length of guess for comparison
        int guesslength = strlen(guess);

        // if guess is the correct length
        if (guesslength == wordsize) {
            correctlength = true;
        }
    }

    // return guess
    return guess;
}





int check_word(string guess, int wordsize, int status[], string choice)
{
    int score = 0;

    // compare guess to choice and score points as appropriate, storing points in status
    // store string length of guess and choice words, for iteration
    int guesslength = strlen(guess);
    int choicelength = strlen(choice);

    // iterate through the guess word, 1 letter at a time, to score points
    for (int i = 0; i < guesslength; i++) {

        // if the guess letter is an exact match to the choice letter in 'poisiton i',
        if (guess[i] == choice[i]) {
            // update 'status i' to 2 (EXACT MATCH)
            status[i] = 2;
            // score 2 points for the exact match
            score += 2;
        }

        // if the guess letter didn't match the choice letter in 'position i',
        if (guess[i] != choice[i]) {
            // check to see if it matches ANY characters in the choice word,
            for (int j = 0; j < choicelength; j++) {
                // if the guess letter in 'position i' matches the choice letter in 'position j',
                if (guess[i] == choice[j]) {
                    // update 'status i' to 1 (CLOSE MATCH)
                    status[i] = 1;
                    // score 1 point for the close match
                    score +=1;
                    break; // if there's a close match, stop looping through choice word
                }
            }
        }
    }

    // HINTS
    // iterate over each letter of the guess
        // iterate over each letter of the choice
            // compare the current guess letter to the current choice letter
                // if they're the same position in the word, score EXACT points (green) and break so you don't compare that letter further
                // if it's in the word, but not the right spot, score CLOSE point (yellow)
        // keep track of the total score by adding each individual letter's score from above

    return score;
}

void print_word(string guess, int wordsize, int status[])
{
    // print word character-for-character with correct color coding, then reset terminal font to normal

    // iterate through status array and guess word, 1 at a time
    for (int i = 0; i < wordsize; i++) {
        // if stored status value = 0
        if (status[i] == 0) {
            // print the corresponding guess character in red
            printf(RED"%c"RESET, guess[i]);
        }

        // if the stored status value = 1
        if (status[i] == 1) {
            // print the corresponding guess character in yellow
            printf(YELLOW"%c"RESET, guess[i]);
        }

        // if the stored status value = 2
        if (status[i] == 2) {
            // print the corresponding guess character in green
            printf(GREEN"%c"RESET, guess[i]);
        }
    }
    printf("\n");
    return;
}
