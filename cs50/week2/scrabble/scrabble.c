#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>

// points assigned to each letter of the alphabet
int POINTS[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};

int compute_score(string word);

int main(void)
{
    // get input words from both players
    string word1 = get_string("Player 1: ");
    string word2 = get_string("Player 2: ");

    // score both words
    int score1 = compute_score(word1);
    int score2 = compute_score(word2);


    // print the winner
    // if score 1 higher
    if (score1 > score2) {
        // player 1 wins
        printf("Player 1 wins!\n");
    }

    // if score 2 higher
    else if (score2 > score1) {
        // player 2 wins
        printf("Player 2 wins!\n");
    }

    // if score 1 and score 2 are equal
    else if (score1 == score2) {
        // tie
        printf("Tie!\n");
    }

    // else, error
    else {
        printf("Error: could not determine a winner.\n");
    }
}



int compute_score(string word) {

    // initate the points scoring
    int score = 0;

    // determine the word (string) length
    int wordlength = strlen(word);

    // iterate through the word length
    for (int i = 0; i < wordlength; i++) {

        // if character is non-alphabetical, score 0
        if (!isalpha(word[i])) {
            score += 0;
        }

        // else, score the alphabetical character
        else {
            // if the character is lowercase
            if (islower(word[i])) {

                int index = word[i] - 97; // obtain a character index from 0-25, indicating which alphabetical character is present
                score += POINTS[index]; // increase score by value associated with that alphabetical character
            }

            else if (isupper(word[i])) {

                int index = word[i] - 65;
                score += POINTS[index];
            }

            else {
                // something went wrong
                printf("Error: could not determine character point value.");
                return 1;
            }
        }
    }
    return score;
}