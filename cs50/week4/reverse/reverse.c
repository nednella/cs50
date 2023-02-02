#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

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
    WAVHEADER *header = malloc(44 * sizeof(BYTE));

    // read the input file to extract the header
    fread(header, 1, 44, input); // file header is 44 bytes in total
    int header_offset = ftell(input); // stream position at the end of the header block (should be equal to 44th byte)

    // Use check_format to ensure WAV format
    // TODO #4
    if (check_format(*header) == false) {
        printf("Input is not a WAV file.");
        return 1;
    }

    // Open output file for writing
    // TODO #5
    // allocate memory for the name of the user-specified output file
    int length = strlen(argv[2]);
    char filename[length];

    // initialise the output file
    FILE *output;

    // create a new WAV file for output
    sprintf(filename, "%s", argv[2]);

    // open the output file
    output = fopen(filename, "w");

    // Write header to file
    // TODO #6
    fwrite(header, 1, 44, output);

    // Use get_block_size to calculate size of block
    // TODO #7
    int block_size = get_block_size(*header);

    // Write reversed audio to file - ONLY INTERESTED IN 45TH BYTE ONWARDS
    // TODO #8

    // initialise a buffer to store each block of audio data
    BYTE buffer[block_size];




    // By downloading input.wav, the file properties tell me the file size is 352,844 bytes!
    // set stream pointer to end of file, then move back by 1 * block_size
    (void) fseek(input, -(block_size), SEEK_END); // current position is now 352,840
    //int current_pos = ftell(input);
    //printf("Here...\n");
    //printf("%i\n", current_pos);

    while(ftell(input) > header_offset) {

    }


    // initialise a buffer the size of 1 block of audio data
    // set stream pointer to end of data
    // move the stream pointer back by block_size
    // for each block
        // check if stream pointer (ftell) > header_offset (as to not read/write the header file)
            // read from the current stream pointer position, 1*block_size of data
            // write the reversed block into output.wav
            // move stream pointer back by 2*block_size















    fclose(input);
    //fclose(output);
    return 0;
}

bool check_format(WAVHEADER header)
{
    // access header, specifically the format array, and check if the chars W, A, V and E are stored in this array
    if (!(header.format[0] == 'W' && header.format[1] == 'A' && header.format[2] == 'V' && header.format[3] == 'E')) {
        return false;
    }

    return true;
}

int get_block_size(WAVHEADER header)
{
    // TODO #7
    // access header, and determine the block size (no. of channels * bits per sample)
    int channels = header.numChannels;
    int bps = header.bitsPerSample / 8;
    int block_size = channels * bps;

    return block_size;
}