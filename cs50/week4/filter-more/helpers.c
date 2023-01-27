#include "helpers.h"
#include <math.h>
#include <stdlib.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    // for greyscale, R G and B values must ALL be equal to eachother (ranging between 0 and 255) to produce a shade of grey
    // use the average of the 3 values to obtain our greyscale value, e.g., gr = (R+G+B)/3

    // iterate through the columns
    for (int i = 0; i < height; i++) {

        // iterate through the rows
        for (int j = 0; j < width; j++) {

            // for each pixel, convert RGB values to doubles
            double R = image[i][j].rgbtRed;
            double G = image[i][j].rgbtGreen;
            double B = image[i][j].rgbtBlue;

            // take average of RGB values
            double avgRGB = ((R + G + B) / 3);

            // set RGB values to new, greyscale value
            image[i][j].rgbtRed = round(avgRGB);
            image[i][j].rgbtGreen = round(avgRGB);
            image[i][j].rgbtBlue = round(avgRGB);
        }
    }
    return;
}





// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    // for horizontal flip, only concerned with editing the pixels w.r.t. their column
    // MUST only iterate over HALF of the columns, otherwise you swap the pixels' positions to reflected position
    // and then swap them back to the original position

    // iterate through the columns
    for (int i = 0; i < height; i++) {

        // iterate through HALF of the rows (to avoid keeping the original image)
        for (int j = 0; j < width/2; j++) {

            // swap pixel in row i, column j, with pixel in row i, position width - 1 - j
            // store current pixels RGB values
            RGBTRIPLE tmp = image[i][j];

            // swap the selected pixels RGB values with the pixels RGB values in position [i][width - 1 - j]
            image[i][j] = image[i][width - 1 - j];

            // swap the pixels RGB values in position [i][width - 1 - j] with the pixels values in the selected pixel [i][j]
            image[i][width - 1 - j] = tmp;
        }
    }
    return;
}





// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    // using box blur method (blur each pixel according to the avg RGB values of its current 3x3 grid)
    // in this case, want to interact with EVERY pixel in the image

    // initialise copied image array and copy original image entirely
    RGBTRIPLE copy[height][width];

    for (int i = 0; i < height; i++) {

        for (int j = 0; j < width; j++) {

            copy[i][j] = image[i][j];
        }
    }


    // iterate through the columns
    for (int i = 0; i < height; i++) {

        // iterate through the rows
        for (int j = 0; j < width; j++) {

            // initialise counters (inside of loop so they are reset for each pixel!)
            double sum_pixel = 0;
            double sum_RGB[] = {0, 0, 0};

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

    // swap in copied image (blurred pixels) to the real image
    for (int i = 0; i < height; i++) {

        for (int j = 0; j < width; j++) {

            image[i][j] = copy[i][j];

        }
     }
    return;
}





// Detect edges
void edges(int height, int width, RGBTRIPLE image[height][width])
{
    return;
}