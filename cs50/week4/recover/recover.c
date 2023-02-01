#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>

typedef uint8_t BYTE;
const int BLOCK = 512;
char *IMAGE = NULL;

// global variables to help decide what actions to take when encountering a new JPEG file in the loaded file
bool firstimage = true;
int imagecount = 0;

int main(int argc, char *argv[])
{
    // check that CLI was used correctly
    if (!(argc == 1)) {
        printf("Usage: ./recover [IMAGE]\n");
        return 1;
    }

    // open specified file in "read" mode, return error message if not found
    // note that fopen doesn't read/write data, it just creates a stream to enable the use of other functions, like fread
    FILE *file = fopen(argv[1], "r");
    if (file == NULL) {
        printf("Error: file not found.\n");
    }

    // initialise the buffer
    BYTE buffer[BLOCK];

    // while there is  >= 1 block of data remaining, load the data into memory with a pointer to the first address of the block, named buffer
    while (fread(buffer, 1, BLOCK, file) == BLOCK) {

        // iterate through the buffer
        for (int i = 0; i < BLOCK; i++) {

            // check for JPEG file existence
            if (buffer[i] == 0xff && buffer[i + 1] == 0xd8 && buffer[i + 2] == 0xff && (buffer[i + 3] & 0xf0) == 0xe0) {

                if (firstimage) {
                    // create a new JPEG file
                    sprintf(IMAGE, "%03i.jpg", imagecount);
                    firstimage = false;
                    imagecount ++;

                    // open the created JPEG file in "write" mode
                    FILE *img = fopen(IMAGE, "w");

                    // write to the JPEG file
                    fwrite(buffer, 1, BLOCK, img);

                }
                else {
                    // close previous JPEG file
                    fclose(IMAGE);

                    // create new JPEG file
                    sprintf(IMAGE, "%03i,jpg", imagecount);
                }
            }

            // if already found a JPEG, then we need to keep writing 512 byte blocks to the currently opened file
            else {
                fwrite(buffer, 1, BLOCK, img);
            }
        }
    }

    // close any remaining images
    fclose(IMAGE);



    // repeat until end of the card:
        // read 512 bytes into a buffer
        // iterate through buffer
            // if start of new JPEG
                // if first JPEG

                // else

            // else
                // if already found JPEG

    // close any remaining files
}
