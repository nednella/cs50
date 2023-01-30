#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>


int main(void) {

    // iterate through the columns
    for (int i = 0; i < height; i++) {

        // iterate through the rows
        for (int j = 0; j < width; j++) {

            // copy original pixel to a COPY image (to allow editing of RGB values without affecting the original)
            copy[i][j] = image[i][j];

            // initialise counters (inside of loop so they are reset for each pixel!)
            double sum_pixel = 0;
            double sum_RGB[] = {0, 0, 0};

            // loop through 3x3 block around [i][j] and check if valid
            // row iteration
            for (int k = (i - 1); k <= (i + 1); k++) {

                // column iteration
                for (int l = (j - 1); l <= (j + 1); j++) {

                    // check if pixel is within valid range of image
                    if (k < 0 || k >= height || l < 0 || l >= width) {
                        continue;
                    }
                    sum_pixel ++;
                    sum_RGB[0] += image[k][l].rgbtRed;
                    sum_RGB[1] += image[k][l].rgbtBlue;
                    sum_RGB[2] += image[k][l].rgbtGreen;

                    //if ((k >= 0) && (k < height) && (l >= 0) && (l < width)) {

                        // count pixel and RGB values (from the ORIGINAL IMAGE)
                        //sum_pixel ++;
                        //sum_RGB[0] += image[k][l].rgbtRed;
                        //sum_RGB[1] += image[k][l].rgbtBlue;
                        //sum_RGB[2] += image[k][l].rgbtGreen;
                    //}

                    //else {
                        //continue;
                    //}
                }
            }

            // calculate average RGB values of the present pixels
            int avg_R = round(sum_RGB[0]/sum_pixel);
            int avg_G = round(sum_RGB[1]/sum_pixel);
            int avg_B = round(sum_RGB[2]/sum_pixel);

            // set COPY IMAGE pixel [i][j]'s RGB values to average of the surrounding pixels
            copy[i][j].rgbtRed = (avg_R);
            copy[i][j].rgbtGreen = (avg_G);
            copy[i][j].rgbtBlue = (avg_B);
        }
    }


}

