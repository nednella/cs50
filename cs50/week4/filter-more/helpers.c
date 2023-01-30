#include "helpers.h"
#include <math.h>
#include <stdlib.h>
#include <stdio.h>

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

    // initialise copy array
    RGBTRIPLE (*copy)[width] = calloc(height, width * sizeof(RGBTRIPLE));
    if (*copy == NULL) {
        printf("Not enough memory available\n");
    }


    // fill copy array
    //for (int i = 0; i < height; i++) {
        //for (int j = 0; j < width; j++) {
            //copy[i][j].rgbtRed = image[i][j].rgbtRed;
            //copy[i][j].rgbtGreen = image[i][j].rgbtGreen;
            //copy[i][j].rgbtBlue = image[i][j].rgbtBlue;
        //}
    //}


    // iterate through the columns
    for (int i = 0; i < height; i++) {

        // iterate through the rows
        for (int j = 0; j < width; j++) {

            // copy original pixel to a COPY image (to allow editing of RGB values without affecting the original)
            copy[i][j] = image[i][j];

            // initialise counters (inside of loop so they are reset for each pixel!)
            double sum_pixel = 0;
            double sum_R = 0;
            double sum_G = 0;
            double sum_B = 0;

            //double sum_RGB[] = {0, 0, 0};

            // for the selected pixel [i][j]
            // check if top left corner is valid
            if (i - 1 >= 0)



                }
            }






    // swap in copied image (blurred pixels) to the real image
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            image[i][j] = copy[i][j];
        }
    }

    free(copy);
    return;
}





// Detect edges
void edges(int height, int width, RGBTRIPLE image[height][width])
{
    return;
}