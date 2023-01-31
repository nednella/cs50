#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>


int main(void) {

    float i = 137;
    float j = 190;
    float a = 135.5;

    float Q = i * i + j * j;
    printf("%f\n", Q);

    float R = sqrt(Q);
    printf("%f\n", R);

    int S = round(R);
    printf("%i\n", S);

    int T = fmin(S,255);
    printf("%i\n", T);

    int V = fmin(round(a),255);
    printf("%i\n", V);
}

