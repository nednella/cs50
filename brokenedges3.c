    // using box blur method (blur each pixel according to the avg RGB values of its current 3x3 grid)
    // in this case, want to interact with EVERY pixel in the image

    // initialise copy array
    RGBTRIPLE (*copy)[width] = calloc(height, width * sizeof(RGBTRIPLE));
    if (copy == NULL) {
        printf("Not enough memory available\n");
    }

    // initialise Gx and Gy matrices
    int Gx[3][3] = {{-1, 0, 1}, {-2, 0, 2}, {-1, 0, 1}};
    int Gy[3][3] = {{-1, -2, -1}, {0, 0, 0}, {1, 2, 1}};

    // iterate through every pixel in the image
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {

            // copy original pixel to a COPY image (to allow editing of RGB values without affecting the original)
            copy[i][j] = image[i][j];

            // initialise counters (inside of loop so they are reset for each pixel!)
            float Rgx = 0;
            float Rgy = 0;
            float Ggx = 0;
            float Ggy = 0;
            float Bgx = 0;
            float Bgy = 0;
            //gx_RGB[];
            //gy_RGB[];

            // for the selected pixel [i][j]
            // loop through its surrounding 3x3 block
            for (int row = i - 1; row <= i + 1; row++) {
                for (int column = j - 1; column <= j + 1; column++) {

                    // check if the pixels are invvalid
                    if (row < 0 || row >= height || column < 0 || column >= width) {
                        // if yes, move onto the next pixel
                        continue;
                    }
                    else {
                        // multiply each pixels R G and B values by the corresponding Gx & Gy value
                        Rgx += (image[row][column].rgbtRed * Gx[row - (i - 1)][column - (i - 1)]);
                        Rgy += (image[row][column].rgbtRed * Gy[row - (i - 1)][column - (i - 1)]);

                        Ggx += (image[row][column].rgbtGreen * Gx[row - (i - 1)][column - (i - 1)]);
                        Ggy += (image[row][column].rgbtGreen * Gy[row - (i - 1)][column - (i - 1)]);

                        Bgx += (image[row][column].rgbtBlue * Gx[row - (i - 1)][column - (i - 1)]);
                        Bgy += (image[row][column].rgbtBlue * Gy[row - (i - 1)][column - (i - 1)]);
                    }
                }
            }

            // calculate the sobel operator for each colour channel
            int new_R = fmin(round(sqrt(Rgx * Rgx + Rgy * Rgy)), 255);
            int new_G = fmin(round(sqrt(Ggx * Ggx + Ggy * Ggy)), 255);
            int new_B = fmin(round(sqrt(Bgx * Bgx + Bgy * Bgy)), 255);

            // replace the copied images' [i][j] pixel RGB values with the new sobel RGB values
            copy[i][j].rgbtRed = new_R;
            copy[i][j].rgbtGreen = new_G;
            copy[i][j].rgbtBlue = new_B;

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