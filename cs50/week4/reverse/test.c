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


    int pos = ftell(test);
    printf("%i\n", pos);


    return 0;
}
