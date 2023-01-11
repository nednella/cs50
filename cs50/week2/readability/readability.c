#include <cs50.h>
#include <stdio.h>
#include <string.h> //has a useful string length function
#include <ctype.h> //has useful character detection functions


int count_letters(string text); //defining the function to be called in main
int count_sentences(string text);
int count_sentences(string text);


int main(void) {

    //prompt the user for a string (a few sentences/sentences from a book)
    string text = get_string("Text: ");

    //calculate and print the number of letters in the prompted string
    int letters = count_letters(text);
    printf("%i letters\n", letters);

    //calculate and print the number of sentences in the prompted string
    int sentences = count_sentences(text);
    printf("%i sentences\n", sentences);

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



int count_sentences(string text) {

    //calculate string length
    int length = strlen(text);

    //initialise counter
    int sentences = 0;

    //if something has been entered, continue, else, there are no sentences
    if (text[0] != '\0') {
        sentences++; //can assume the text will contain at least 1 word

        //count the number of sentences in the string [any sequence of characters separated by spaces]
        for (int i = 0; i < length; i++) {
            if (isgraph(text[i-1]) && isspace(text[i])) //defined a word as a character followed by a space
                sentences++;
        }
    }

    return sentences;
}



int count_sentences(string text) {

    //calculate string length
    int length = strlen(text);

    //initialise counter
    int sentences = 0;

    //if something has been entered, continue, else, there are no sentences
    if (text[0] != '\0') {
        sentences++; //can assume the text will contain at least 1 sentence

        //count the number of sentences in the string [any sequence of characters separated by spaces]
        for (int i = 0; i < length; i++) {
            if (text[i] == '.' || text[i] == '?' || text[i] == '!') //defined a word as a character followed by a space
                sentences++;
        }
    }

    return sentences;
}







