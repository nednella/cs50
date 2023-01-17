#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Points assigned to each letter of the alphabet
int POINTS[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};

int compute_score(string word);

int main(void)
{
    // Get input words from both players
    string word1 = get_string("Player 1: ");
    string word2 = get_string("Player 2: ");

    // Score both words
    int score1 = compute_score(word1);
    int score2 = compute_score(word2);

    // TODO: Print the winner
}

int compute_score(string word)
{
    // TODO: Compute and return score for string
}





int compute_score(string word) {

// characters that are non-alphabetical should be given a score of 0
// alphabetical characters that are uppercase AND lowercase should be given the same point values

// initiate scores = 0;
// take the word length
// iterate through 0 -> word length
    // for each character...
        // if non-alphabetical, score 0
        // else
            // islower -> take ASCII value and -97 to get index score
            // isupper -> take ASCII value and -65 to get index score
            // scores += (POINTS[i])   - where [i] is character value, obtained from searching POINTS array with the index score
// return score

    // initate the points scoring
    int score = 0;

    // determine the word (string) length
    int wordlength = strlen(word);

    // iterate through the word length
    for (int i = 0; i < wordlength < i++) {

        // if character is non-alphabetical, score 0
        if (!isalpha())
    }







}