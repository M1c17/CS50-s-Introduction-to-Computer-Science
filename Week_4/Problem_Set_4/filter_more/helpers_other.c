#include "helpers.h"
#include <math.h>
#include <stdio.h>


// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for(int j = 0; j < width; j++)
        {
            RGBTRIPLE *ptr = &image[i][j];
            unsigned  int average = round((float)(ptr -> rgbtBlue + ptr -> rgbtGreen + ptr -> rgbtRed) / 3);
            ptr -> rgbtBlue = average;
            ptr -> rgbtGreen = average;
            ptr -> rgbtRed = average;
        }
    }
    return;
}

// Reflect image horizontally
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

// Detect edges
void edges(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE edges_arr[height][width];
    int Gx[] = {-1, 0, 1, -2, 0, 2, -1, 0, 1};
    int Gy[] = {-1, -2, -1, 0, 0, 0, 1, 2, 1};

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            //detect boundaries between objects
            //the color of one side is defferent than the color of the other side

            int idx = 0;
            unsigned int newRedX = 0, newGreenX = 0, newBlueX = 0;
            unsigned int newRedY = 0, newGreenY = 0, newBlueY = 0;
            //build 3 X 3 grid
            for (int newX = i - 1; newX < i + 2; newX++)
            {
                for (int newY = j - 1; newY < j + 2; newY++)
                {
                    //boundaries
                    if (newX >= 0 && newY >= 0 && newX < height && newY < width)
                    {
                        //compute gx and gy for each channel of red green and blue
                        newRedX += (Gx[idx] * image[newX][newY].rgbtRed);
                        newGreenX += (Gx[idx] * image[newX][newY].rgbtGreen);
                        newBlueX += (Gx[idx] * image[newX][newY].rgbtBlue);

                        newRedY += (Gy[idx] * image[newX][newY].rgbtRed);
                        newGreenY += (Gy[idx] * image[newX][newY].rgbtGreen);
                        newBlueY += (Gy[idx] * image[newX][newY].rgbtBlue);
                    }
                    idx++;
                }
            }
            //compute the total amount of color that should be in the new pixel
            //compute each new channel value
            edges_arr[i][j].rgbtRed = fmin(round(sqrt((float)(newRedX * newRedX) + (newRedY * newRedY))), 255);
            edges_arr[i][j].rgbtGreen = fmin(round(sqrt((float)(newGreenX * newGreenX) + (newGreenY * newGreenY))), 255);
            edges_arr[i][j].rgbtBlue = fmin(round(sqrt((float)(newBlueX * newBlueX) + (newBlueY * newBlueY))), 255);
                
        }
    }
    for (int k = 0; k < height; k++)
    {
        for (int l = 0; l < width; l++)
        {
            RGBTRIPLE *ptr = &image[k][l];
            ptr -> rgbtRed = edges_arr[k][l].rgbtRed;
            ptr -> rgbtGreen = edges_arr[k][l].rgbtGreen;
            ptr -> rgbtBlue = edges_arr[k][l].rgbtBlue;
        }
    }
}
