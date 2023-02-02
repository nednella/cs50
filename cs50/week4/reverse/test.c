#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "wav.h"



int main(void)
{
    FILE *test = fopen("test.txt", "r");
    if (test == NULL) {
        printf("Error: unable to open file.\n");
        return 1;
    }

    // initialise a buffer to store the data from text.txt
    char buffer[10];

    fread(buffer, 1, 10, test);

    int block_size = 5;

    int pos = ftell(test);
    //printf("%i\n", pos);

    // move stream pointer back to the start
    fseek(test, 0, SEEK_SET);
    char character = fgetc(test);
    printf("%c\n", character);

    // move stream pointer back to the start + 1
    fseek(test, 1, SEEK_SET);
     character = fgetc(test);
    printf("%c\n", character);

    // move stream pointer back to the start + 2
    fseek(test, 2, SEEK_SET);
     character = fgetc(test);
    printf("%c\n", character);

    // move stream pointer to the end
    fseek(test, -1, SEEK_END);
     character = fgetc(test);
    printf("%c\n", character);

    // move stream pointer to the 2nd last character
    fseek(test, -(block_size), SEEK_END);
     character = fgetc(test);
    printf("%c\n", character);



    return 0;
}
