#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "wav.h"

bool check_format(WAVHEADER header);
int get_block_size(WAVHEADER header);

int main(int argc, char *argv[])
{
    // Ensure proper usage
    // TODO #1
    if (!(argc == 3)) {
        printf("Usage: ./reverse [input.wav] [output.wav]");
        return 1;
    }

    // Open input file for reading
    // TODO #2
    FILE *file = fopen(argv[1], "r");
    if (file == NULL) {
        printf("Error: file not found.\n");
    }

    // Read header into an array
    // TODO #3
    // allocate memory to store the file header
    WAVHEADER header;

    // read the input file to extract the header
    fread(header, 1, 44, file); // file header is 44 bytes in total

    // Use check_format to ensure WAV format
    // TODO #4
    if (check_format(header) == false) {
        printf("Input is not a WAV file.");
        return 1;
    }

    // Open output file for writing
    // TODO #5
    fopen();

    // Write header to file
    // TODO #6

    // Use get_block_size to calculate size of block
    // TODO #7

    // Write reversed audio to file
    // TODO #8

    fclose(file);
    return 0;
}

bool check_format(WAVHEADER header)
{
    // access WAVHEADER, specifically the format array, and check if the chars W, A, V and E are stored in this array
    if (!(WAVHEADER.format[0] == "W" && WAVHEADER.format[1] == "A" && WAVHEADER.format[2] == "V" && WAVHEADER.format[3] == "E")) {
        return false;
    }

    return true;
}

int get_block_size(WAVHEADER header)
{
    // TODO #7
    return 0;
}