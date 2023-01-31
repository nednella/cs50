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


    // once header block is found, open a new JPEG file

    // keep writing data in chunks of 512 bytes until a new JPEG file header is reached

    // close old file

    // repeat

}