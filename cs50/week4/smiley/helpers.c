#include "helpers.h"

void colorize(int height, int width, RGBTRIPLE image[height][width])
{
    // choice colour - CYAN
    int R_value = 0;
    int G_value = 100;
    int B_value = 100;

    // loop through every pixel in the image
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {

            // if the pixel is black
            if (image[i][j].rgbtRed == 0 && image[i][j].rgbtGreen == 0 && image[i][j].rgbtBlue == 0) {

                // access the RGB values and set them to a colour of choice
                image[i][j].rgbtRed = R_value;
                image[i][j].rgbtGreen = G_value;
                image[i][j].rgbtBlue = B_value;
            }
        }
    }

    return;
}
