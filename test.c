#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include <stdint.h>

typedef uint8_t  BYTE;

typedef struct
{
    BYTE  R;
    BYTE  G;
    BYTE  B;
}
RGBTRIPLE;

int main(void) {

    int height = 2;
    int width = 2;

    RGBTRIPLE image[height][width] = malloc(sizeof(RGBTRIPLE) * height * width); // variable length array

    image[0][0].R = 100;
    image[0][0].G = 100;
    image[0][0].B = 100;

    image[0][1].R = 120;
    image[0][1].G = 120;
    image[0][1].B = 120;

    image[1][0].R = 160;
    image[1][0].G = 160;
    image[1][0].B = 160;

    image[1][1].R = 180;
    image[1][1].G = 180;
    image[1][1].B = 180;


}
