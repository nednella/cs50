#include "helpers.h"
#include <math.h>

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
    // as a test, set every single pixel to BLACK rgbt[0, 0, 0]
    // iterate through the rows
    //for (int i = 0; i < height; i++) {
        // iterate through the columns
        //for (int j = 0; j < width; j++) {
            // set all RGB values to 0 in each pixel within row i
            //image[i][j].rgbtRed = 0;
            //image[i][j].rgbtGreen = 0;
            //image[i][j].rgbtBlue = 0;
       //}
    //}
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

    // initialise counters
    double sum_pixels = 0;

    double sum_R = 0;
    double sum_G = 0;
    double sum_B = 0;

    // iterate through the columns
    for (int i = 0; i < height; i++) {

        // iterate through the rows
        for (int j = 0; j < width; j++) {

            // take RGB values of ALL pixels within 3x3 of [i][j], assuming pixels exist

            // for current pixel
            // count the pixel as present
            sum_pixels ++;

            // add the RGB values to the respective counters
            sum_R += image[i][j].rgbtRed;
            sum_G += image[i][j].rgbtGreen;
            sum_B += image[i][j].rgbtBlue;


            // do the same for remaining pixels within 3x3 of [i][j], assuming they exist
            // loop through 3x3 of [i][j] and check if valid
            // row iteration
            for (int k = i - 1; k <= i + 1; k++) {

                // column iteration
                for (int l = j - 1; l <= j + 1; j++) {

                    // check if pixel is within valid range of image
                    if (k >= 0 && k < height && l >= 0 && l < width) {

                        // count pixel and RGB values
                        sum_pixels ++;
                        sum_R += image[i + k][j + l].rgbtRed; // note 3x3 is w.r.t. current pixel [i][j] so must sum i & k, j & l
                        sum_G += image[i + k][j + l].rgbtBlue;
                        sum_B += image[i + k][j + l].rgbtGreen;
                    }
                }
            }

            // calculate average RGB values of the present pixels
            double avg_R = round(sum_R/sum_pixels);
            double avg_G = round(sum_G/sum_pixels);
            double avg_B = round(sum_B/sum_pixels);

            // set current pixel [i][j]'s RGB values to average of the surrounding pixels
            image[i][j].rgbtRed = (avg_R);
            image[i][j].rgbtGreen = (avg_G);
            image[i][j].rgbtBlue = (avg_B);
        }
    }
    return;
}





// Detect edges
void edges(int height, int width, RGBTRIPLE image[height][width])
{
    return;
}