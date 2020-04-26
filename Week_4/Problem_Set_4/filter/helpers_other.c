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

            // min= 0, max=255
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
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    //iterate over pixel
    RGBTRIPLE blurr_row[height][width];
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            unsigned int newRed = 0, newGreen = 0, newBlue = 0;
            float count = 0;
            for (int h = i - 1; h  < i + 2; h++)
            {

                for (int w = j - 1; w < j + 2; w++)
                {
                    if(h >= 0 && w >= 0 && h < height && w < width)
                    {
                        newRed += image[h][w].rgbtRed;
                        newGreen += image[h][w].rgbtGreen;
                        newBlue += image[h][w].rgbtBlue;
                        count++;
                    }
                }
            }
        blurr_row[i][j].rgbtRed = round(newRed/count);
        blurr_row[i][j].rgbtGreen = round(newGreen/count);
        blurr_row[i][j].rgbtBlue = round(newBlue/count);
        }
    }
    for (int k = 0; k < height; k++)
    {
        for (int l = 0; l < width; l++)
        {
            RGBTRIPLE *ptr = &image[k][l];
            ptr -> rgbtRed = blurr_row[k][l].rgbtRed;
            ptr -> rgbtGreen = blurr_row[k][l].rgbtGreen;
            ptr -> rgbtBlue = blurr_row[k][l].rgbtBlue;
        }
    }
}

