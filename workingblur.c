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
            if (i - 1 >= 0 && j - 1 >= 0) {
                sum_pixel ++;
                sum_R += image[i - 1][j - 1].rgbtRed;
                sum_G += image[i - 1][j - 1].rgbtBlue;
                sum_B += image[i - 1][j - 1].rgbtGreen;
            }

            // check if top middle is valid
            if (i - 1 >= 0) {
                sum_pixel ++;
                sum_R += image[i - 1][j].rgbtRed;
                sum_G += image[i - 1][j].rgbtBlue;
                sum_B += image[i - 1][j].rgbtGreen;
            }

            // check if top right is valid
            if (i - 1 >= 0 && j < width) {
                sum_pixel ++;
                sum_R += image[i - 1][j + 1].rgbtRed;
                sum_G += image[i - 1][j + 1].rgbtBlue;
                sum_B += image[i - 1][j + 1].rgbtGreen;
            }

            // check if middle left is valid
            if (j - 1 >= 0) {
                sum_pixel ++;
                sum_R += image[i][j - 1].rgbtRed;
                sum_G += image[i][j - 1].rgbtBlue;
                sum_B += image[i][j - 1].rgbtGreen;
            }

            // CURRENT PIXEL
            sum_pixel ++;
            sum_R += image[i][j].rgbtRed;
            sum_G += image[i][j].rgbtBlue;
            sum_B += image[i][j].rgbtGreen;

            // check if middle right is valid
            if (j < width) {
                sum_pixel ++;
                sum_R += image[i][j + 1].rgbtRed;
                sum_G += image[i][j + 1].rgbtBlue;
                sum_B += image[i][j + 1].rgbtGreen;
            }

            // check if bottom left is valid
            if (i + 1 < height && j >= 0) {
                sum_pixel ++;
                sum_R += image[i + 1][j - 1].rgbtRed;
                sum_G += image[i + 1][j - 1].rgbtBlue;
                sum_B += image[i + 1][j - 1].rgbtGreen;
            }

            // check if bottom middle is valid
            if (i + 1 < height) {
                sum_pixel ++;
                sum_R += image[i + 1][j].rgbtRed;
                sum_G += image[i + 1][j].rgbtBlue;
                sum_B += image[i + 1][j].rgbtGreen;
            }

            // check if bottom right is valid
            if (i + 1 < height && j + 1 < width) {
                sum_pixel ++;
                sum_R += image[i + 1][j + 1].rgbtRed;
                sum_G += image[i + 1][j + 1].rgbtBlue;
                sum_B += image[i + 1][j + 1].rgbtGreen;
            }

            // average out the summed RGB values
            int avg_R = round(sum_R/sum_pixel);
            int avg_G = round(sum_G/sum_pixel);
            int avg_B = round(sum_B/sum_pixel);

            // replace the copied images' [i][j] pixel RGB values with the new averaged RGV values
            copy[i][j].rgbtRed = avg_R;
            copy[i][j].rgbtBlue = avg_G;
            copy[i][j].rgbtGreen = avg_B;

         }
    }