#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    // check that CLI was used correctly


    // if yes, open the image in question
    char *filename = argv[];

    FILE *f = fopen(filename, "r"); // open file in read mode


    // start searching data from NULL -> END, for the beginning of a jpeg
    // key for a JPEG file header...
        // 1st byte always 0xff
        // 2nd byte always 0xd8
        // 3rd byte always 0xff
        // 4th byte always 0xeX... (where X is 0 - F in hexadecimal)

    fread(data, size, number, inptr);

    // loop through data starting from [X=0] and iterate 1 at a time
        // if buffer[X] == 0xff
            // if buffer[X+1] == 0xd8
                // if buffer [X+2] == 0xff
                    // if buffer [X+3] == 0xe0 (combine 0xf0 or some shit to consider all 16 possibilities in 1 step without 16 logical OR operators)

                        // once header block is found,
                        // open a new JPEG file and start writing the data 1 byte at a time
                        // keep writing until [X+n] = 0xff
                                    // if buffer[X+n+1] == 0xd8
                                        // if buffer [X+n+2] == 0xff
                                            // if buffer [X+n+3] == 0xe0

    // keep writing data in chunks of 512 bytes until a new JPEG file header is reached

    // close old file

    // repeat

}