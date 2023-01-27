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

















            // loop through 3x3 of [i][j] and check if valid
            // row iteration
            for (int k = (i - 1); k <= (i + 1); k++) {

                // column iteration
                for (int l = (j - 1); l <= (j + 1); j++) {

                    // check if pixel is within valid range of image
                    if ((k >= 0) && (k < height) && (l >= 0) && (l < width)) {

                        // count pixel and RGB values (from the ORIGINAL IMAGE)
                        sum_pixel ++;
                        sum_RGB[0] += image[k][l].rgbtRed;
                        sum_RGB[1] += image[k][l].rgbtBlue;
                        sum_RGB[2] += image[k][l].rgbtGreen;
                    }

                    else {
                        continue;
                    }
                }
            }














            // take RGB values of ALL pixels within 3x3 of [i][j], assuming pixels exist

            // current pixel
            sum_pixel ++;
            sum_RGB[0] += image[i][j].rgbtRed;
            sum_RGB[1] += image[i][j].rgbtGreen;
            sum_RGB[2] += image[i][j].rgbtBlue;

            // if upper left exists
            if ((i - 1) >= 0 && (j - 1) >= 0) {

                sum_pixel ++;

                sum_RGB[0] += image[i - 1][j - 1].rgbtRed;
                sum_RGB[1] += image[i - 1][j - 1].rgbtBlue;
                sum_RGB[2] += image[i - 1][j - 1].rgbtGreen;

            }

            // if upper middle exists
            if ((i - 1) >= 0) {

                sum_pixel ++;

                sum_RGB[0] += image[i - 1][j].rgbtRed;
                sum_RGB[1] += image[i - 1][j].rgbtBlue;
                sum_RGB[2] += image[i - 1][j].rgbtGreen;
            }

            // if upper right exists
            if ((i - 1) >= 0 && (j + 1) < width) {

                sum_pixel ++;

                sum_RGB[0] += image[i - 1][j + 1].rgbtRed;
                sum_RGB[1] += image[i - 1][j + 1].rgbtBlue;
                sum_RGB[2] += image[i - 1][j + 1].rgbtGreen;
            }

            // if middle left exists
            if ((j - 1) >= 0) {

                sum_pixel ++;

                sum_RGB[0] += image[i][j - 1].rgbtRed;
                sum_RGB[1] += image[i][j - 1].rgbtBlue;
                sum_RGB[2] += image[i][j - 1].rgbtGreen;
            }

            // if middle right exists
            if ((j + 1) < width) {

                sum_pixel ++;

                sum_RGB[0] += image[i][j + 1].rgbtRed;
                sum_RGB[1] += image[i][j + 1].rgbtBlue;
                sum_RGB[2] += image[i][j + 1].rgbtGreen;
            }

            // lower left
            if ((i + 1) < height && (j - 1) >= 0) {

                sum_pixel ++;

                sum_RGB[0] += image[i + 1][j - 1].rgbtRed;
                sum_RGB[1] += image[i + 1][j - 1].rgbtBlue;
                sum_RGB[2] += image[i + 1][j - 1].rgbtGreen;
            }

            // lower middle
            if ((i + 1) < height) {

                sum_pixel ++;

                sum_RGB[0] += image[i + 1][j].rgbtRed;
                sum_RGB[1] += image[i + 1][j].rgbtBlue;
                sum_RGB[2] += image[i + 1][j].rgbtGreen;
            }

            // lower right
            if((i + 1) < height && (j + 1) < width) {

                sum_pixel ++;

                sum_RGB[0] += image[i + 1][j + 1].rgbtRed;
                sum_RGB[1] += image[i + 1][j + 1].rgbtBlue;
                sum_RGB[2] += image[i + 1][j + 1].rgbtGreen;
            }

}
