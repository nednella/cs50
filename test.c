#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>


int main(void) {

    int R = 255;
    int G = 243;
    int B = 17;

    float avgRGB = ((R + G + B) / 3);
    printf("%f\n", avgRGB);

    int gr = round(avgRGB);
    printf ("%i\n", gr);
}
