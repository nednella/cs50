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















                // if upper left exists
            if ((i - 1) >= 0 && (j - 1) >= 0) {

                sum_pixels ++;

                sum_R += image[i - 1][j - 1].rgbtRed;
                sum_G += image[i - 1][j - 1].rgbtBlue;
                sum_B += image[i - 1][j - 1].rgbtGreen;

            }

            // if upper middle exists
            if ((i - 1) >= 0) {

                sum_pixels ++;

                sum_R += image[i - 1][j].rgbtRed;
                sum_G += image[i - 1][j].rgbtBlue;
                sum_B += image[i - 1][j].rgbtGreen;
            }

            // if upper right exists
            if ((i - 1) >= 0 && (j + 1) < width) {

                sum_pixels ++;

                sum_R += image[i - 1][j + 1].rgbtRed;
                sum_G += image[i - 1][j + 1].rgbtBlue;
                sum_B += image[i - 1][j + 1].rgbtGreen;
            }

            // if middle left exists
            if ((j - 1) >= 0) {

                sum_pixels ++;

                sum_R += image[i][j - 1].rgbtRed;
                sum_G += image[i][j - 1].rgbtBlue;
                sum_B += image[i][j - 1].rgbtGreen;
            }

            // if middle right exists
            if ((j + 1) < width) {

                sum_pixels ++;

                sum_R += image[i][j + 1].rgbtRed;
                sum_G += image[i][j + 1].rgbtBlue;
                sum_B += image[i][j + 1].rgbtGreen;
            }

            // lower left
            if ((i + 1) < height && (j - 1) >= 0) {

                sum_pixels ++;

                sum_R += image[i + 1][j - 1].rgbtRed;
                sum_G += image[i + 1][j - 1].rgbtBlue;
                sum_B += image[i + 1][j - 1].rgbtGreen;
            }

            // lower middle
            if ((i + 1) < height) {

                sum_pixels ++;

                sum_R += image[i + 1][j].rgbtRed;
                sum_G += image[i + 1][j].rgbtBlue;
                sum_B += image[i + 1][j].rgbtGreen;
            }

            // lower right
            if((i + 1) < height && (j + 1) < width) {

                sum_pixels ++;

                sum_R += image[i + 1][j + 1].rgbtRed;
                sum_G += image[i + 1][j + 1].rgbtBlue;
                sum_B += image[i + 1][j + 1].rgbtGreen;
            }
}
