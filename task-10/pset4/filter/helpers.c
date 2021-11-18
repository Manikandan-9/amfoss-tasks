#include "helpers.h"
#include <math.h>
// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i=0;i<height;i++){
        for (int j=0;j<width;j++){
            RGBTRIPLE pixel = image[i][j];

            int average = round((pixel.rgbtBlue+pixel.rgbtGreen+pixel.rgbtRed)/3.0);
            image[i][j].rgbtBlue = average;
            image[i][j].rgbtGreen = average;
            image[i][j].rgbtRed = average;
        }

    }
    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i=0;i<height;i++){
        for (int j=0;j<width;j++){

            RGBTRIPLE pixel = image[i][j];
            int sepiaRed = round(.393 * pixel.rgbtRed + .769 * pixel.rgbtGreen + .189 * pixel.rgbtBlue);
            int sepiaGreen = round(.349 * pixel.rgbtRed + .686 * pixel.rgbtGreen + .168 * pixel.rgbtBlue);
            int sepiaBlue = round(.272 * pixel.rgbtRed + .534 * pixel.rgbtGreen + .131 * pixel.rgbtBlue);

            image[i][j].rgbtRed = sepiaRed > 255 ? 255 : sepiaRed;
            image[i][j].rgbtGreen = sepiaGreen > 255 ? 255 : sepiaGreen;
            image[i][j].rgbtBlue = sepiaBlue > 255 ? 255 : sepiaBlue;
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE temp[height][width];

    for (int i=0;i<height;i++){
        int current_position = 0;
        for (int j=width-1;j>=0;j--,current_position++){


            temp[i][current_position] = image[i][j];
        }
    }



    for (int i=0;i<height;i++){
        for (int j=0;j<width;j++){

            image[i][j] = temp[i][j];
        }
    }

    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{

    RGBTRIPLE temp[height][width];

    for (int row=0;row<height;row++){
        for (int col=0;col<width;col++){

            int count = 0;
            int rowcoords[] = {row-1,row,row+1};
            int colcoords[] = {col-1,col,col+1};
            float totalR = 0;
            float totalG = 0;
            float totalB = 0;

            for(int i =0;i<3;i++){
                for(int j = 0;j<3;j++){
                    int current_row = rowcoords[i];
                    int current_col = colcoords[j];

                    if (current_row>=0 && current_row<height && current_col>=0 && current_col < width){
                        RGBTRIPLE pixel = image[current_row][current_col];
                        totalR += pixel.rgbtRed;
                        totalG += pixel.rgbtGreen;
                        totalB += pixel.rgbtBlue;
                        count++;

                    }
                }
            }

            temp[row][col].rgbtRed = round(totalR/count);
            temp[row][col].rgbtGreen = round(totalG/count);
            temp[row][col].rgbtBlue = round(totalB/count);
        }
    }
    for (int i=0;i<height;i++){
        for (int j=0;j<width;j++){

            image[i][j] = temp[i][j];
        }
    }

    return;
}
