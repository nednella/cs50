#include <cs50.h>
#include <stdio.h>
#include <string.h> //has a useful string length function
#include <ctype.h> //has useful character detection functions


int count_letters(string text); //defining the function to be called in main
int count_words(string text);



int main(void) {

    //prompt the user for a string (a few words/sentences from a book)
    string text = get_string("Text: ");

    //calculate and print the number of letters in the prompted string
    int letters = count_letters(text);
    printf("%i letters\n", letters);

    //calculate and print the number of words in the prompted string
    int words = count_words(text);
    printf("%i words\n", words);

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
    int words = 1; //can assume a sentence will contain at least 1 word

    //count the number of words in the string [any sequence of characters separated by spaces]
    if ()
    for (int i = 0; i < length; i++) {
        if (isgraph(text[i-1]) && isspace(text[i]))
            words++;
    }

    return words;
}





