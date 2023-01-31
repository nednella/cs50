#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>

typedef uint8_t BYTE;

const int BLOCK = 512;

// global variables to help decide what actions to take when encountering a new JPEG file in the loaded file
bool firstimage = true;
int imagecount = 1;

int main(int argc, char *argv[])
{
    // check that CLI was used correctly
    if (!(argc == 1)) {
        printf("Usage: ./recover [IMAGE]\n");
        return 1;
    }

    FILE *file = fopen(argv[1], "r"); // open specified file in "read" mode, return error message if not found
    // note that fopen doesn't read/write data, it just creates a stream to enable the use of other functions, like fread
    if (file == NULL) {
        printf("Error: file not found.\n");
    }




    // initialise the buffer
    BYTE buffer[512];

    // while there is  >= 1 block of data remaining, load the data into memory with a pointer to the first address of the block, named buffer
    while (fread(buffer, 1, BLOCK, file) == BLOCK) {

        // iterate through the buffer
        for (int i = 0; i < BLOCK; i++) {

            // check for JPEG file existence
            if (buffer[i] == 0xff && buffer[i + 1] == 0xd8 && buffer[i + 2] == 0xff && (buffer[i + 3] & 0xf0) == 0xe0) {

                if (firstimage) {
                    // create a new JPEG file
                    //sprintf(buffer, "%03i.jpg", imagecount);
                    firstimage = false;
                    imagecount ++;
                }
                else {
                    // close previous JPEG file


                    // create new JPEG file
                    //sprintf(buffer, "%03i,jpg", imagecount);
                }
            }




        }
    }
    // repeat until end of the card:
        // read 512 bytes into a buffer
        // iterate through buffer
            // if start of new JPEG
                // if first JPEG

                // else

            // else
                // if already found JPEG

    // close any remaining files







    // start searching data from NULL -> END, for the beginning of a jpeg
    // key for a JPEG file header...
        // 1st byte always 0xff
        // 2nd byte always 0xd8
        // 3rd byte always 0xff
        // 4th byte always 0xeX... (where X is 0 - F in hexadecimal)

    //fread(data, size, number, inptr);
        // buildin a condition to ensure that the file has enough data remaining for fread, to read

    // loop through data starting from [X=0] and iterate 1 at a time
        // if buffer[X] == 0xff
            // if buffer[X+1] == 0xd8
                // if buffer [X+2] == 0xff
                    // if buffer [X+3] == 0xe0 (combine 0xf0 or some shit to consider all 16 possibilities in 1 step without 16 logical OR operators)

                        // once header block is found,
                        // open a new JPEG file (###.jpg) starting at 001.jpg, in the order you find them (use function, count++, %03i)
                        //FILE *f = fopen(001.jpg, "w"); // open image in write mode
                        //fwrite(data, size, number, outptr);
                        // start writing all data in chunks of b12 bytes until [X+n] = 0xff
                                    // if buffer[X+n+1] == 0xd8
                                        // if buffer [X+n+2] == 0xff
                                            // if buffer [X+n+3] == 0xe0

    // keep writing data in chunks of 512 bytes until a new JPEG file header is reached

    // close old file

    // repeat

}
