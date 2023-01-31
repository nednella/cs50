// using box blur method (blur each pixel according to the avg RGB values of its current 3x3 grid)
    // in this case, want to interact with EVERY pixel in the image

    // initialise copy array
    RGBTRIPLE (*copy)[width] = calloc(height, width * sizeof(RGBTRIPLE));
    if (copy == NULL) {
        printf("Not enough memory available\n");
    }

    // initialise gx and gy matrices
    int Gx[3][3] = {{-1, 0, 1}, {-2, 0, 2}, {-1, 0, 1}};
    int Gy[3][3] = {{-1, -2, -1}, {0, 0, 0}, {1, 2, 1}};

    // iterate through the image
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {

            // copy original pixel to a COPY image (to allow editing of RGB values without affecting the original)
            copy[i][j] = image[i][j];

            // initialise variables (inside of loop so they are reset for each pixel!)
            double gxR = 0;
            double gyR = 0;

            double gxG = 0;
            double gyG = 0;

            double gxB = 0;
            double gyB = 0;

            //double sum_gx[] = {0, 0, 0}; // 1 channel for R, G and B
            //double sum_gy[] = {0, 0, 0}; // 1 channel for R, G and B



            // for the selected pixel [i][j]
            // loop through its surrounding 3x3 block of pixels
            for (int row = i - 1; row <= i + 1; row++) {
                for (int column = j - 1; column <= j + 1; column++) {

                    // check if the pixels are invalid
                    if (row < 0 || row >= height || column < 0 || column >= width) {
                        // if yes, move onto the next pixel
                        continue;
                    }

                    // if valid
                    else {

                        // multiply the each pixel in the 3x3 by both the Gx and Gy matrix values in the same position
                        // Gx
                        gxR += image[row][column].rgbtRed * Gx[row - (i - 1)][column - (j - 1)];
                        gxG += image[row][column].rgbtGreen * Gx[row - (i - 1)][column - (j - 1)];
                        gxB += image[row][column].rgbtBlue * Gx[row - (i - 1)][column - (j - 1)];

                        // Gy
                        gyR += image[row][column].rgbtRed * Gx[row - (i - 1)][column - (j - 1)];
                        gyG += image[row][column].rgbtGreen * Gx[row - (i - 1)][column - (j - 1)];
                        gyB += image[row][column].rgbtBlue * Gx[row - (i - 1)][column - (j - 1)];
                    }
                }
            }

            // combine Gx and Gy values for each colour channel, capping to 255 where needed
            int new_R = fmin(round(sqrt((gxR * gxR) + (gyR * gyR))), 255);
            int new_G = fmin(round(sqrt((gxG * gxG) + (gyG * gyG))), 255);
            int new_B = fmin(round(sqrt((gxB * gxB) + (gyB * gyB))), 255);

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