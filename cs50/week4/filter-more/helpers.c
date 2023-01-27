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

    // initialise counters
    int sum_pixels = 0;

    int sum_red = 0;
    int sum_green = 0;
    int sum_blue = 0

    // iterate through the columns
    for (int i = 0; i < height; i++) {

        // iterate through the rows
        for (int j = 0; j < width; j++) {

            // take RGB values of all pixels within 3x3 of [i][j], assuming pixels exist
            // add pixels one at a time if they exist

            // upper left
            if (image[i - 1][j - 1])

            // upper middle
            if (image[i - 1][j])

            // upper right
            if (image[i - 1][j + 1])

            // middle left
            if (image[i][j - 1])

            // middle right
            if (image[i][j + 1])

            // lower left
            if ([i + 1][j - 1])

            // lower middle
            if (image[i + 1][j])


            // lower right
            if(image[i + 1][j + 1])





            // store RGB values of all pixels within 3x3 of selected pixel, where pixel 5 is the current pixel [i][j]
            // take average of all (up to 9) pixels' GREEN values
            double p1r = image[i - 1][j - 1].rgbtRed;
            double p2r = image[i - 1][j].rgbtRed;
            double p3r = image[i - 1][j + 1].rgbtRed;
            double p4r = image[i][j - 1].rgbtRed;
            double p5r = image[i][j].rgbtRed;
            double p6r = image[i][j + 1].rgbtRed;
            double p7r = image[i + 1][j - 1].rgbtRed;
            double p8r = image[i + 1][j].rgbtRed;
            double p9r = image[i + 1][j + 1].rgbtRed;

            double avgR = ((p1r + p2r + p3r + p4r + p5r + p6r + p7r + p8r + p9r) / 9);
            int newR = round(avgR);

            // take average of all (up to 9) pixels' GREEN values
            double p1g = image[i - 1][j - 1].rgbtGreen;
            double p2g = image[i - 1][j].rgbtGreen;
            double p3g = image[i - 1][j + 1].rgbtGreen;
            double p4g = image[i][j - 1].rgbtGreen;
            double p5g = image[i][j].rgbtGreen;
            double p6g = image[i][j + 1].rgbtGreen;
            double p7g = image[i + 1][j - 1].rgbtGreen;
            double p8g = image[i + 1][j].rgbtGreen;
            double p9g = image[i + 1][j + 1].rgbtGreen;

            double avgG = ((p1g + p2g + p3g + p4g + p5g + p6g + p7g + p8g + p9g) / 9);
            int newG = round(avgG);

            // take average of all (up to 9) pixels' GREEN values
            double p1b = image[i - 1][j - 1].rgbtBlue;
            double p2b = image[i - 1][j].rgbtBlue;
            double p3b = image[i - 1][j + 1].rgbtBlue;
            double p4b = image[i][j - 1].rgbtBlue;
            double p5b = image[i][j].rgbtGreen;
            double p6b = image[i][j + 1].rgbtBlue;
            double p7b = image[i + 1][j - 1].rgbtBlue;
            double p8b = image[i + 1][j].rgbtBlue;
            double p9b = image[i + 1][j + 1].rgbtBlue;

            double avgB = ((p1b + p2b + p3b + p4b + p5b + p6b + p7b + p8b + p9b) / 9);
            int newB = round(avgB);

            // replace current pixel [i][j]'s RGB values with averaged value
            image[i][j].rgbtRed = newR;
            image[i][j].rgbtGreen = newG;
            image[i][j].rgbtBblue = newB;
        }
    }



    return;
}





// Detect edges
void edges(int height, int width, RGBTRIPLE image[height][width])
{
    return;
}