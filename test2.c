#include <cs50.h>
#include <stdio.h>
#include <string.h> //has a useful string length function
#include <ctype.h>


int count_letters(string text); //declaration of the function


int main(void) {

    //Prompt the user for a string (a few words/sentences from a book)
    string text = get_string("String: ");

    //calculate string length
    int length = strlen(text);

    //initialise counters
    int letters = 0;
    int words = 1; //allowed to assume a sentence will contain at least 1 word
    int sentences = 0;

    //count the number of letters in the string [a to z, lowercase AND uppercase]
    for (int i = 0; i < length; i++) {
        if (isalpha(text[i]))
            letters++;
    }

    //count the number of words in the string [any sequences of characters separated by spaces]
    for(int j = 0; j < length; j++) {
        if(isspace(text[j]) && text[j-1] )
            words++;
    }


    //count the number of sentences in the string (any occurence of . ! ? should indicate the end of a sentence)



    //print the results
    printf("Letter count: %d\n", letters);
    printf("Word count: %d\n", words);
    printf("Sentence count: %d\n", sentences);

}



    //calculate the average number of letters per 100 words (L)


    //calcualte the aerage number of sentences per 100 words (S)


    //calculate the grade of the text using the Coleman-Liau index


    //index = 0.0588 * L - 0.296 * S - 15.8


    //round off the calculated grade (index) to the nearest whole number


    //print the rounded index as a grade (if <1 print "Before Grade 1", if >16 print "Grade 16+")


