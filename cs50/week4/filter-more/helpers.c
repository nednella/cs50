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
    // in this case, want to interact with EVERY pixel, unlike horizontal reflect

    // iterate through the columns
    for (int i = 0; i < height; i++) {

        // iterate through the rows
        for (int j = 0; j < width; j++) {

            // store RGB values of all pixels within 3x3 of selected pixel, where pixel 5 is the current pixel [i][j]
            RGBTRIPLE p1 = image[i - 1][j - 1];
            RGBTRIPLE p2 = image[i - 1][j];
            RGBTRIPLE p3 = image[i - 1][j + 1];
            RGBTRIPLE p4 = image[i][j - 1];
            RGBTRIPLE p5 = image[i][j];
            RGBTRIPLE p6 = image[i][j + 1];
            RGBTRIPLE p7 = image[i + 1][j - 1];
            RGBTRIPLE p8 = image[i + 1][j];
            RGBTRIPLE p9 = image[i + 1][j + 1];

            // take average of all (up to 9) pixels
            



        }
    }



    return;
}





// Detect edges
void edges(int height, int width, RGBTRIPLE image[height][width])
{
    return;
}