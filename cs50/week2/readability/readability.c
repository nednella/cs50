#include <cs50.h>
#include <stdio.h>
#include <string.h>

int main(void) {

//Prompt the user for a string (a few words/sentences from a book)
text = get_string = ("String: ");

//count the number of letters in the string (a to z, lowercase AND uppercase)
for (int i = 0, i < strlen(text), i++) {
    if (text[i])
}


//count the number of words in the string (a string of characters separated by a space)


//count the number of sentences in the string (any occurence of . ! ? should indicate the end of a sentence)


//calculate the average number of letters per 100 words (L)


//calcualte the aerage number of sentences per 100 words (S)


//calculate the grade of the text using the Coleman-Liau index



//index = 0.0588 * L - 0.296 * S - 15.8



//round off the calculated grade (index) to the nearest whole number


//print the rounded index as a grade (if <1 print "Before Grade 1", if >16 print "Grade 16+")



}