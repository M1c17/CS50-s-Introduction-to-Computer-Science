#include "helpers.h"
#include <math.h>
#include <stddef.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>


// Convert image to grayscale
// take an image and turn it into a black-white version
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    //Iterate over each pixel
    for(int i = 0; i < height; i++)
    {
        for(int j = 0; j < width; j++)
        {
            // Goes to the references and access the address data
            RGBTRIPLE *ptr = &image[i][j];
            unsigned int average = round((float) (ptr -> rgbtBlue + ptr -> rgbtGreen + ptr -> rgbtRed) / 3);
            //changing the original value of each pixels to
            //these average values
            ptr -> rgbtBlue = average;
            ptr -> rgbtGreen = average;
            ptr -> rgbtRed = average;
        }

    }
    return;
}


// Convert image to sepia
// take an image and turn into a sepia version
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    for(int i = 0; i < height; i++)
    {
        for(int j = 0; j < width; j++)
        {
            RGBTRIPLE *ptr = &image[i][j];
            unsigned int sepia_rgb[3];

            sepia_rgb[0] = round((float)(.393 * ptr -> rgbtRed) + (.769 * ptr -> rgbtGreen) + (.189 * ptr -> rgbtBlue));
            sepia_rgb[1] = round((float)(.349 * ptr -> rgbtRed) + (.686 * ptr -> rgbtGreen) + (.168 * ptr -> rgbtBlue));
            sepia_rgb[2] = round((float)(.272 * ptr -> rgbtRed + .534 * ptr -> rgbtGreen + .131 * ptr -> rgbtBlue));

            for(int k = 0; k < 3; k++)
            {
                if (sepia_rgb[k] > 255)
                {
                    sepia_rgb[k] = 255;
                }
                if (k == 0)
                {
                    ptr -> rgbtRed = sepia_rgb[k];
                }
                else if (k == 1)
                {
                    ptr -> rgbtGreen = sepia_rgb[k];
                }
                else
                {
                    ptr -> rgbtBlue = sepia_rgb[k];
                }

            }
        }
    }
    return;
}
// Reflect image horizontally
// take image and reflect it horinzontally.
void swap(RGBTRIPLE *a, RGBTRIPLE *b);
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        int n = 1;
        for (int j = 0; j < width/2; j++)
        {
            swap(&image[i][j], &image[i][width - n]);
            n++;
        }
    }
    return;
}

void swap(RGBTRIPLE *a, RGBTRIPLE *b)
{
    RGBTRIPLE temp = *a;
    *a = *b;
    *b = temp;
}

// Blur image
// take image and turn it into a box-blurred version
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE blurr_row[height][width];
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            unsigned int newRed = 0, newGreen = 0, newBlue = 0;
            float counter = 0;
            int dirs[9][2] = {{0,0}, {-1,-1}, {-1,0}, {-1,1}, {0,1}, {1,1},
                             {1,0}, {1,-1}, {0,-1}};

            for (int k = 0; k < 9; k++)
            {
                int newX = i + dirs[k][0];
                int newY = j + dirs[k][1];
                //is this taking the start_i position ??????
                if (newX >= 0 && newY >= 0 && newX < height && newY < width)
                {
                        newRed += image[newX][newY].rgbtRed;
                        newGreen += image[newX][newY].rgbtGreen;
                        newBlue += image[newX][newY].rgbtBlue;
                        counter++;
                }
            }
            blurr_row[i][j].rgbtRed = round(newRed/counter);
            blurr_row[i][j].rgbtGreen = round(newGreen/counter);
            blurr_row[i][j].rgbtBlue = round(newBlue/counter);
        }
    }
    for (int x = 0; x < height; x++)
    {
        for (int y = 0; y < width; y++)
        {
            RGBTRIPLE *ptr = &image[x][y];
            ptr -> rgbtGreen = blurr_row[x][y].rgbtGreen;
            ptr -> rgbtRed = blurr_row[x][y].rgbtRed;
            ptr -> rgbtBlue = blurr_row[x][y].rgbtBlue;
        }
    }
}