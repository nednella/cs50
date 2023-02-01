#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>

typedef uint8_t BYTE;
const int BLOCK = 512;
char *IMAGE = NULL;


int main(int argc, char *argv[])
{
    // check that CLI was used correctly
    if (!(argc == 2)) {
        printf("Usage: ./recover [IMAGE]\n");
        return 1;
    }

    // open specified file in "read" mode, return error message if not found
    // note that fopen doesn't read/write data, it just creates a stream to enable the use of other functions, like fread
    FILE *file = fopen(argv[1], "r");
    if (file == NULL) {
        printf("Error: file not found.\n");
    }

    // allocate memory for a buffer, filename, and initialise variables
    BYTE buffer[BLOCK];
    char filename[10];

    FILE *image;
    int imagecount = 0;

    // while there is  >= 1 block of data remaining, load the data into memory with a pointer to the first address of the block, named buffer
    while (fread(buffer, 1, BLOCK, file) == BLOCK) {

        // check for JPEG file existence
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0) {

            // if JPEG is not the first image found, close the previous JPEG
            if (!(imagecount == 0)) {
                fclose(image);
            }

            // create a new JPEG file
            sprintf(filename, "%03i.jpg", imagecount);
            imagecount ++;

            // open the created JPEG file in "write" mode
            image = fopen(filename, "w");

            // write to the JPEG file
            fwrite(buffer, 1, BLOCK, image);

        }

        // if already found a JPEG, then we need to keep writing 512 byte blocks to the currently opened file
        else if (imagecount > 0) {
            fwrite(buffer, 1, BLOCK, image);
        }
    }

    // close any remaining files
    fclose(file);
    fclose(image);

    //free(buffer);
    return 0;
}
