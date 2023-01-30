// Detect edges
void edges(int height, int width, RGBTRIPLE image[height][width])
{
// using box blur method (blur each pixel according to the avg RGB values of its current 3x3 grid)
    // in this case, want to interact with EVERY pixel in the image

    // initialise copy array
    RGBTRIPLE (*copy)[width] = calloc(height, width * sizeof(RGBTRIPLE));
    if (copy == NULL) {
        printf("Not enough memory available\n");
    }

    // iterate through the image
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {

            // copy original pixel to a COPY image (to allow editing of RGB values without affecting the original)
            copy[i][j] = image[i][j];

            // initialise variables (inside of loop so they are reset for each pixel!)
            double sumR_gx = 0;
            double sumR_gy = 0;

            double sumG_gx = 0;
            double sumG_gy = 0;

            double sumB_gx = 0;
            double sumB_gy = 0;

            //double sum_gx[] = {0, 0, 0}; // 1 channel for R, G and B
            //double sum_gy[] = {0, 0, 0}; // 1 channel for R, G and B




            // for the selected pixel [i][j]
            // loop through its surrounding 3x3 block
            for (int row = i - 1; row <= i + 1; row++) {
                for (int column = j - 1; column <= j + 1; column++) {

                    // check if the pixels are invalid
                    if (row < 0 || row >= height || column < 0 || column >= width) {
                        // if yes, move onto the next pixel
                        continue;
                    }
                    else {

                        // if valid... go through every pixel in the 3x3, for cases when that pixel is valid
                        // for the top left
                        if (row == i - 1 && column == j - 1) {
                            // for RED
                            sumR_gx += (-1 * image[i - 1][j - 1].rgbtRed);
                            sumR_gy += (-1 * image[i - 1][j - 1].rgbtRed);

                            // for GREEN
                            sumG_gx += (-1 * image[i - 1][j - 1].rgbtGreen);
                            sumG_gy += (-1 * image[i - 1][j - 1].rgbtGreen);

                            // for BLUE
                            sumB_gx += (-1 * image[i - 1][j - 1].rgbtBlue);
                            sumB_gy += (-1 * image[i - 1][j - 1].rgbtBlue);
                        }

                        // for the top middle
                        if (row == i - 1) {
                            // for RED
                            sumR_gx += (0 * image[i - 1][j].rgbtRed);
                            sumR_gy += (-2 * image[i - 1][j].rgbtRed);

                            // for GREEN
                            sumG_gx += (0 * image[i - 1][j].rgbtGreen);
                            sumG_gy += (-2 * image[i - 1][j].rgbtGreen);

                            // for BLUE
                            sumB_gx += (0 * image[i - 1][j].rgbtBlue);
                            sumB_gy += (-2 * image[i - 1][j].rgbtBlue);
                        }

                        // for the top right
                        if (row == i - 1 && column == j + 1) {
                            // for RED
                            sumR_gx += (1 * image[i - 1][j + 1].rgbtRed);
                            sumR_gy += (-1 * image[i - 1][j + 1].rgbtRed);

                            // for GREEN
                            sumG_gx += (1 * image[i - 1][j + 1].rgbtGreen);
                            sumG_gy += (-1 * image[i - 1][j + 1].rgbtGreen);

                            // for BLUE
                            sumB_gx += (1 * image[i - 1][j + 1].rgbtRed);
                            sumB_gy += (-1 * image[i - 1][j + 1].rgbtBlue);
                        }

                        // for the middle left
                        if (column == j - 1) {
                            // for RED
                            sumR_gx += (-2 * image[i][j - 1].rgbtRed);
                            sumR_gy += (0 * image[i][j - 1].rgbtRed);

                            // for GREEN
                            sumG_gx += (-2 * image[i][j - 1].rgbtGreen);
                            sumG_gy += (0 * image[i][j - 1].rgbtGreen);

                            // for BLUE
                            sumB_gx += (-2 * image[i][j - 1].rgbtRed);
                            sumB_gy += (0 * image[i][j - 1].rgbtBlue);
                        }


                        // for the current pixel [i][j]
                        // for RED
                        sumR_gx += (0 * image[i][j].rgbtRed);
                        sumR_gy += (0 * image[i][j].rgbtRed);

                        // for GREEN
                        sumG_gx += (0 * image[i][j].rgbtGreen);
                        sumG_gy += (0 * image[i][j].rgbtGreen);

                        // for BLUE
                        sumB_gx += (0 * image[i][j].rgbtRed);
                        sumB_gy += (0 * image[i][j].rgbtBlue);


                        // for the middle right
                        if (column == j + 1) {
                            // for RED
                            sumR_gx += (2 * image[i][j + 1].rgbtRed);
                            sumR_gy += (0 * image[i][j + 1].rgbtRed);

                            // for GREEN
                            sumG_gx += (2 * image[i][j + 1].rgbtGreen);
                            sumG_gy += (0 * image[i][j + 1].rgbtGreen);

                            // for BLUE
                            sumB_gx += (2 * image[i][j + 1].rgbtRed);
                            sumB_gy += (0 * image[i][j + 1].rgbtBlue);
                        }



                        // for the bottom left
                        if (row == i + 1 && column == j - 1) {
                            // for RED
                            sumR_gx += (-1 * image[i + 1][j - 1].rgbtRed);
                            sumR_gy += (1 * image[i + 1][j - 1].rgbtRed);

                            // for GREEN
                            sumG_gx += (-1 * image[i + 1][j - 1].rgbtGreen);
                            sumG_gy += (1 * image[i + 1][j - 1].rgbtGreen);

                            // for BLUE
                            sumB_gx += (-1 * image[i + 1][j - 1].rgbtRed);
                            sumB_gy += (1 * image[i + 1][j - 1].rgbtBlue);
                        }


                        // for the bottom middle
                        if (row == i + 1) {
                            // for RED
                            sumR_gx += (0 * image[i + 1][j].rgbtRed);
                            sumR_gy += (2 * image[i + 1][j].rgbtRed);

                            // for GREEN
                            sumG_gx += (0 * image[i + 1][j].rgbtGreen);
                            sumG_gy += (2 * image[i + 1][j].rgbtGreen);

                            // for BLUE
                            sumB_gx += (0 * image[i + 1][j].rgbtRed);
                            sumB_gy += (2 * image[i + 1][j].rgbtBlue);
                        }


                        // for the bottom right
                        if (row == i + 1 && column == j + 1) {
                            // for RED
                            sumR_gx += (1 * image[i + 1][j + 1].rgbtRed);
                            sumR_gy += (1 * image[i + 1][j + 1].rgbtRed);

                            // for GREEN
                            sumG_gx += (1 * image[i + 1][j + 1].rgbtGreen);
                            sumG_gy += (1 * image[i + 1][j + 1].rgbtGreen);

                            // for BLUE
                            sumB_gx += (1 * image[i + 1][j + 1].rgbtRed);
                            sumB_gy += (1 * image[i + 1][j + 1].rgbtBlue);
                        }
                    }
                }
            }

            // combine Gx and Gy values for each colour channel, capping to 255 where needed
            int new_R = fmin(round(sqrt((sumR_gx * sumR_gx)+(sumR_gy * sumR_gy))), 255);
            int new_G = fmin(round(sqrt((sumG_gx * sumG_gx)+(sumG_gy * sumG_gy))), 255);
            int new_B = fmin(round(sqrt((sumB_gx * sumB_gx)+(sumB_gy * sumB_gy))), 255);

            // replace the copied images' [i][j] pixel RGB values with the new RGB values
            copy[i][j].rgbtRed = new_R;
            copy[i][j].rgbtBlue = new_G;
            copy[i][j].rgbtGreen = new_B;
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