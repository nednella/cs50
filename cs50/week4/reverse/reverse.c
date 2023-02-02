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
    if (!(argc == 3)) {
        printf("Usage: ./reverse [input.wav] [output.wav]\n");
        return 1;
    }

    // Open input file for reading
    FILE *input = fopen(argv[1], "r");
    if (input == NULL) {
        printf("Error: file not found.\n");
    }

    // Read header into an array
    // allocate memory to store the file header
    WAVHEADER *header = malloc(44 * sizeof(BYTE));

    // read the input file to extract the header
    fread(header, 1, 44, input); // file header is 44 bytes in total
    int header_offset = ftell(input); // stream position at the end of the header block (should be equal to 44th byte)

    // Use check_format to ensure WAV format
    if (check_format(*header) == false) {
        printf("Input is not a WAV file.\n");
        return 1;
    }

    // Open output file for writing
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
    fwrite(header, 1, 44, output);

    // Use get_block_size to calculate size of block
    int block_size = get_block_size(*header);

    // Write reversed audio to file
    // initialise a buffer to store the size of 1 block of audio data
    BYTE buffer[block_size];
    BYTE temp[block_size];

    // set stream pointer to end of file, then move back by 1 * block_size
    // by downloading input.wav, the file properties tell me the file size is 352,844 bytes!
    (void) fseek(input, -(block_size), SEEK_END); // current position is now 352,840

    // loop through the data in reverse, 1 block at a time, stopping when we reach the files' header metadata
    while(ftell(input) >= header_offset) {

        // read into the buffer from current stream position, for a total of block_size bytes
        fread(buffer, 1, block_size, input);












        // reverse the data block and write it into the temp buffer, whilst maintaining the channels
        for (int i = block_size - 1, j = 0; i >= 0; i--, j++) { // --- ERROR HERE, must consider channels 1 and 2 when reversing the data

            temp[j] = buffer[i];
        }















        // write the reversed data into the output file
        fwrite(buffer, 1, block_size, output);

        // move the stream pointer back by 2*block_size
        (void) fseek(input, -(2 * block_size), SEEK_CUR);
    }

    fclose(input);
    fclose(output);
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
    // access header, and determine the block size (no. of channels * bits per sample)
    int channels = header.numChannels;
    int bps = header.bitsPerSample / 8;
    int block_size = channels * bps;

    return block_size;
}