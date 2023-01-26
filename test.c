#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>


int main(void) {

    double R = 255;
  double  G = 243;
    double B = 17;

    double avgRGB = (float) ((R + G + B) / 3);
    printf("%f\n", avgRGB);

    int gr = round(avgRGB);
    printf ("%i\n", gr);
}
