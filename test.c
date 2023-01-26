#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>


int main(void) {

    float R = 255;
    float  G = 243;
    float B = 17;

    float avgRGB = (float) ((R + G + B) / 3);
    printf("%.2f\n", avgRGB);

    int gr = round(avgRGB);
    printf ("%i\n", gr);
}
