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
    FILE *input = fopen(argv[1], "r");
    if (input == NULL) {
        printf("Error: file not found.\n");
    }

    // Read header into an array
    // TODO #3
    // allocate memory to store the file header
    WAVHEADER *header = NULL; // = malloc(44 * sizeof(BYTE));

    // read the input file to extract the header
    fread(header, 1, 44, input); // file header is 44 bytes in total

    // Use check_format to ensure WAV format
    // TODO #4
    if (check_format(*header) == false) {
        printf("Input is not a WAV file.");
        return 1;
    }

    // Open output file for writing
    // TODO #5
    // allocate memory for the name of the user-specified output file
    //int length = strlen(argv[2]);
    char filename = malloc(length * sizeof(char));

    // initialise the output file
    FILE *output;

    // create a new WAV file for output
    sprintf(filename, "%s", argv[2]);

    // open the output file
    output = fopen(filename, "w");




    // Write header to file
    // TODO #6

    // Use get_block_size to calculate size of block
    // TODO #7

    // Write reversed audio to file
    // TODO #8

    fclose(input);
    return 0;
}

bool check_format(WAVHEADER header)
{
    // access WAVHEADER, specifically the format array, and check if the chars W, A, V and E are stored in this array
    if (!(header.format[0] == 'W' && header.format[1] == 'A' && header.format[2] == 'V' && header.format[3] == 'E')) {
        return false;
    }

    return true;
}

int get_block_size(WAVHEADER header)
{
    // TODO #7
    return 0;
}