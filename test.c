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

    //RGBTRIPLE *image = malloc(sizeof(RGBTRIPLE) * height * width); // variable length array
    RGBTRIPLE image[height][width];

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

    RGBTRIPLE copy[height][width];

    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            copy[i][j] = image[i][j];
            printf("Copy row: %i\n", i);
            printf("Copy column: %i\n", j);
            printf("R: %i\n", copy[i][j].R);
            printf("G: %i\n", copy[i][j].R);
            printf("B: %i\n", copy[i][j].R);
            printf("\n");
        }
    }
}
