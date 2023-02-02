#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "wav.h"



int main(void)
{
    int block_size = 4;
    int buffer[] = {1, 2, 3, 4};
    int temp[] = {0, 0, 0, 0};

    // store buffer in reverse, into temporary
    for (int i = block_size, j = 0; i >= 0; i--, j++) {

            temp[j] = buffer[i];
        }

    // print temporary array in full
    for (int i = 0; i < block_size; i++) {
        printf("%i\n", temp[i]);
    }

    return 0;
}