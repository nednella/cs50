#include <cs50.h>
#include <stdio.h>
#include <string.h> //has a useful string length function
#include <ctype.h> //has useful character detection functions
#include <math.h> //has some useful maths functions (e.g., rounding)


int count_letters(string text); //defining the function to be called in main
int count_words(string text);
int count_sentences(string text);


int main(void) {

    //prompt the user for a string (a few sentences/sentences from a book)
    string text = get_string("Text: ");

    //calculate and the number of letters in the prompted string
    int letters = count_letters(text);

    //calculate and the number of words in the prompted string
    int words = count_words(text);

    //calculate and the number of sentences in the prompted string
    int sentences = count_sentences(text);

    //print the resulting calculations
    printf("%i letters\n", letters);
    printf("%i words\n", words);
    printf("%i sentences\n", sentences);

    //calculate L, average number of letters per 100 words
    float L = (letters / words) * 100;
    printf("%f letters per 100 words\n", L);

    //calculate S, average number of sentences per 100 words
    float S = (sentences / words) * 100;
    printf("%f sentences per 100 words\n", S);

    //calculate the grade of the text using the Coleman-Liau index
    //index = 0.0588 * L - 0.296 * S - 15.8

    //round off the calculated grade (index) to the nearest whole number


    //print the rounded index as a grade (if <1 print "Before Grade 1", if >16 print "Grade 16+")

}



int count_letters(string text) {

    //calculate string length
    int length = strlen(text);

    //initialise counter
    int letters = 0;

    //count the number of letters in the string [a to z, lowercase AND uppercase]
    for (int i = 0; i < length; i++) {
        if (isalpha(text[i]))
            letters++;
    }

    return letters;
}



int count_words(string text) {

    //calculate string length
    int length = strlen(text);

    //initialise counter
    int words = 0;

    //if something has been entered, continue, else, there are no sentences
    if (text[0] != '\0') {
        words++; //can assume the text will contain at least 1 word (number of spaces = n - 1, where n = number of words)

        //count the number of words in the string [any sequence of characters separated by spaces]
        for (int i = 0; i < length; i++) {
            if (isgraph(text[i-1]) && isspace(text[i])) //defined a word as a character followed by a space
                words++;
        }
    }

    return words;
}



int count_sentences(string text) {

    //calculate string length
    int length = strlen(text);

    //initialise counter
    int sentences = 0;

    //if something has been entered, continue, else, there are no sentences
    if (text[0] != '\0') {
        //count the number of sentences in the string [any sequence of characters separated by spaces]
        for (int i = 0; i < length; i++) {
            if (text[i] == '.' || text[i] == '?' || text[i] == '!') //defined a word as a character followed by a space
                sentences++;
        }
    }

    return sentences;
}