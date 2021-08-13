#include "helpers.h"
#include <math.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int average;
            // we get average of these three values for each pixel
            average = round((float)(image[i][j].rgbtRed + image[i][j].rgbtGreen + image[i][j].rgbtBlue) / 3);
            image[i][j].rgbtRed = average;
            image[i][j].rgbtGreen = average;
            image[i][j].rgbtBlue = average;
        }
    }
    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            // using round from math.h and formula for sepia colors
            int sepiaRed, sepiaGreen, sepiaBlue;
            sepiaRed = round((float)(.393 * image[i][j].rgbtRed) + (float)(.769 * image[i][j].rgbtGreen) + 
                             (float)(.189 * image[i][j].rgbtBlue));
            // 0xff = white, when value is bigger than 0xff it sets it to max = 0xff
            if (sepiaRed > 0xFF)
            {
                sepiaRed = 0xFF;
            }
            sepiaGreen = round((float)(.349 * image[i][j].rgbtRed) + (float)(.686 * image[i][j].rgbtGreen) + 
                               (float)(.168 * image[i][j].rgbtBlue));
            if (sepiaGreen > 0xFF)
            {
                sepiaGreen = 0xFF;
            }
            sepiaBlue = round((float)(.272 * image[i][j].rgbtRed) + (float)(.534 * image[i][j].rgbtGreen) + 
                              (float)(.131 * image[i][j].rgbtBlue));
            if (sepiaBlue > 0xFF)
            {
                sepiaBlue = 0xFF;
            }
            image[i][j].rgbtRed = sepiaRed;
            image[i][j].rgbtGreen = sepiaGreen;
            image[i][j].rgbtBlue = sepiaBlue;
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width / 2; j++)
        {
            // making temp RGBTRIPLE struct for moving pixels
            RGBTRIPLE tmp;
            tmp = image[i][j];
            image[i][j] = image[i][width - j - 1];
            image[i][width - j - 1] = tmp;
        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE copy[height][width];
    float averageRed, averageGreen, averageBlue;
    // we make a copy of original image so we can take original values of pixels from it
    for (int r = 0; r < height; r++)
    {
        for (int c = 0; c < width; c++)
        {
            copy[r][c].rgbtRed = image[r][c].rgbtRed;
            copy[r][c].rgbtGreen = image[r][c].rgbtGreen;
            copy[r][c].rgbtBlue = image[r][c].rgbtBlue;
        }
    }
    
    for (int h = 0; h < height; h++)
    {
        for (int w = 0; w < width; w++)
        {
            //if pixel is in corner
            if (w == 0 && h == 0)
            {
                averageRed = (float)(copy[h][w].rgbtRed + copy[h][w + 1].rgbtRed + copy[h + 1][w].rgbtRed + copy[h + 1][w + 1].rgbtRed) / 4;
                averageGreen = (float)(copy[h][w].rgbtGreen + copy[h][w + 1].rgbtGreen + copy[h + 1][w].rgbtGreen + 
                                       copy[h + 1][w + 1].rgbtGreen) / 4;
                averageBlue = (float)(copy[h][w].rgbtBlue + copy[h][w + 1].rgbtBlue + copy[h + 1][w].rgbtBlue + copy[h + 1][w + 1].rgbtBlue) / 4;
                averageRed = round(averageRed);
                averageBlue = round(averageBlue);
                averageGreen = round(averageGreen);
                image[h][w].rgbtRed = averageRed;
                image[h][w].rgbtGreen = averageGreen;
                image[h][w].rgbtBlue = averageBlue;
            }
            else if (w == 0 && h == (height - 1))
            {
                averageRed = (float)(copy[h - 1][w].rgbtRed + copy[h - 1][w + 1].rgbtRed + copy[h][w].rgbtRed + copy[h][w + 1].rgbtRed) / 4;
                averageGreen = (float)(copy[h - 1][w].rgbtGreen + copy[h - 1][w + 1].rgbtGreen + copy[h][w].rgbtGreen + 
                                       copy[h][w + 1].rgbtGreen) / 4;
                averageBlue = (float)(copy[h - 1][w].rgbtBlue + copy[h - 1][w + 1].rgbtBlue + copy[h][w].rgbtBlue + copy[h][w + 1].rgbtBlue) / 4;
                averageRed = round(averageRed);
                averageGreen = round(averageGreen);
                averageBlue = round(averageBlue);
                image[h][w].rgbtRed = averageRed;
                image[h][w].rgbtGreen = averageGreen;
                image[h][w].rgbtBlue = averageBlue;
            }
            else if (h == 0 && w == (width - 1))
            {
                averageRed = (float)(copy[h][w - 1].rgbtRed + copy[h][w].rgbtRed + copy[h + 1][w - 1].rgbtRed + copy[h + 1][w].rgbtRed) / 4;
                averageGreen = (float)(copy[h][w - 1].rgbtGreen + copy[h][w].rgbtGreen + copy[h + 1][w - 1].rgbtGreen + 
                                       copy[h + 1][w].rgbtGreen) / 4;
                averageBlue = (float)(copy[h][w - 1].rgbtBlue + copy[h][w].rgbtBlue + copy[h + 1][w - 1].rgbtBlue + copy[h + 1][w].rgbtBlue) / 4;
                averageRed = round(averageRed);
                averageGreen = round(averageGreen);
                averageBlue = round(averageBlue);
                image[h][w].rgbtRed = averageRed;
                image[h][w].rgbtGreen = averageGreen;
                image[h][w].rgbtBlue = averageBlue;
            }
            else if (h == (height - 1) && w == (width - 1))
            {
                averageRed = (float)(copy[h - 1][w - 1].rgbtRed + copy[h - 1][w].rgbtRed + copy[h][w - 1].rgbtRed + copy[h][w].rgbtRed) / 4;
                averageBlue = (float)(copy[h - 1][w - 1].rgbtBlue + copy[h - 1][w].rgbtBlue + copy[h][w - 1].rgbtBlue + copy[h][w].rgbtBlue) / 4;
                averageGreen = (float)(copy[h - 1][w - 1].rgbtGreen + copy[h - 1][w].rgbtGreen + copy[h][w - 1].rgbtGreen + 
                                       copy[h][w].rgbtGreen) / 4;
                averageRed = round(averageRed);
                averageGreen = round(averageGreen);
                averageBlue = round(averageBlue);
                image[h][w].rgbtRed = averageRed;
                image[h][w].rgbtGreen = averageGreen;
                image[h][w].rgbtBlue = averageBlue;
            }
            else if (w == 0 && (h > 0 && h < height - 1))
            {
                averageRed = (float)(copy[h - 1][w].rgbtRed + copy[h - 1][w + 1].rgbtRed + copy[h][w].rgbtRed + copy[h][w + 1].rgbtRed + 
                                     copy[h + 1][w].rgbtRed + copy[h + 1][w + 1].rgbtRed) / 6;
                averageGreen = (float)(copy[h - 1][w].rgbtGreen + copy[h - 1][w + 1].rgbtGreen + copy[h][w].rgbtGreen + copy[h][w + 1].rgbtGreen + 
                                       copy[h + 1][w].rgbtGreen + copy[h + 1][w + 1].rgbtGreen) / 6;
                averageBlue = (float)(copy[h - 1][w].rgbtBlue + copy[h - 1][w + 1].rgbtBlue + copy[h][w].rgbtBlue + copy[h][w + 1].rgbtBlue + 
                                      copy[h + 1][w].rgbtBlue + copy[h + 1][w + 1].rgbtBlue) / 6;
                averageRed = round(averageRed);
                averageGreen = round(averageGreen);
                averageBlue = round(averageBlue);
                image[h][w].rgbtRed = averageRed;
                image[h][w].rgbtGreen = averageGreen;
                image[h][w].rgbtBlue = averageBlue;
            }
            else if (w == (width - 1) && (h > 0 && h < height - 1))
            {
                averageRed = (float)(copy[h - 1][w - 1].rgbtRed + copy[h - 1][w].rgbtRed + copy[h][w - 1].rgbtRed + copy[h][w].rgbtRed + 
                                     copy[h + 1][w - 1].rgbtRed + copy[h + 1][w].rgbtRed) / 6;
                averageGreen = (float)(copy[h - 1][w - 1].rgbtGreen + copy[h - 1][w].rgbtGreen + copy[h][w - 1].rgbtGreen + 
                                       copy[h][w].rgbtGreen + copy[h + 1][w - 1].rgbtGreen + copy[h + 1][w].rgbtGreen) / 6;
                averageBlue = (float)(copy[h - 1][w - 1].rgbtBlue + copy[h - 1][w].rgbtBlue + copy[h][w - 1].rgbtBlue + copy[h][w].rgbtBlue + 
                                      copy[h + 1][w - 1].rgbtBlue + copy[h + 1][w].rgbtBlue) / 6;
                averageRed = round(averageRed);
                averageGreen = round(averageGreen);
                averageBlue = round(averageBlue);
                image[h][w].rgbtRed = averageRed;
                image[h][w].rgbtGreen = averageGreen;
                image[h][w].rgbtBlue = averageBlue;
            }
            else if (h == 0 && (w > 0 &&  w < width - 1))
            {
                averageRed = (float)(copy[h][w - 1].rgbtRed + copy[h][w].rgbtRed + copy[h][w + 1].rgbtRed + copy[h + 1][w - 1].rgbtRed + 
                                     copy[h + 1][w].rgbtRed + copy[h + 1][w + 1].rgbtRed) / 6;
                averageGreen = (float)(copy[h][w - 1].rgbtGreen + copy[h][w].rgbtGreen + copy[h][w + 1].rgbtGreen + copy[h + 1][w - 1].rgbtGreen + 
                                       copy[h + 1][w].rgbtGreen + copy[h + 1][w + 1].rgbtGreen) / 6;
                averageBlue = (float)(copy[h][w - 1].rgbtBlue + copy[h][w].rgbtBlue + copy[h][w + 1].rgbtBlue + copy[h + 1][w - 1].rgbtBlue + 
                                      copy[h + 1][w].rgbtBlue + copy[h + 1][w + 1].rgbtBlue) / 6;
                averageRed = round(averageRed);
                averageGreen = round(averageGreen);
                averageBlue = round(averageBlue);
                image[h][w].rgbtRed = averageRed;
                image[h][w].rgbtGreen = averageGreen;
                image[h][w].rgbtBlue = averageBlue;
            }
            else if (h == height - 1 && (w > 0 && w < width - 1))
            {
                averageRed = (float)(copy[h - 1][w - 1].rgbtRed + copy[h - 1][w].rgbtRed + copy[h - 1][w + 1].rgbtRed + copy[h][w - 1].rgbtRed + 
                                     copy[h][w].rgbtRed + copy[h][w + 1].rgbtRed) / 6;
                averageGreen = (float)(copy[h - 1][w - 1].rgbtGreen + copy[h - 1][w].rgbtGreen + copy[h - 1][w + 1].rgbtGreen + 
                                       copy[h][w - 1].rgbtGreen + copy[h][w].rgbtGreen + copy[h][w + 1].rgbtGreen) / 6;
                averageBlue = (float)(copy[h - 1][w - 1].rgbtBlue + copy[h - 1][w].rgbtBlue + copy[h - 1][w + 1].rgbtBlue + 
                                      copy[h][w - 1].rgbtBlue + copy[h][w].rgbtBlue + copy[h][w + 1].rgbtBlue) / 6;
                averageRed = round(averageRed);
                averageGreen = round(averageGreen);
                averageBlue = round(averageBlue);
                image[h][w].rgbtRed = averageRed;
                image[h][w].rgbtGreen = averageGreen;
                image[h][w].rgbtBlue = averageBlue;
                
            }
            else
            {
                averageRed = (float)(copy[h - 1][w - 1].rgbtRed + copy[h - 1][w].rgbtRed + copy[h - 1][w + 1].rgbtRed + copy[h][w - 1].rgbtRed + 
                                     copy[h][w].rgbtRed + copy[h][w + 1].rgbtRed + copy[h + 1][w - 1].rgbtRed + copy[h + 1][w].rgbtRed + 
                                     copy[h + 1][w + 1].rgbtRed) / 9;
                averageGreen = (float)(copy[h - 1][w - 1].rgbtGreen + copy[h - 1][w].rgbtGreen + copy[h - 1][w + 1].rgbtGreen + 
                                       copy[h][w - 1].rgbtGreen + copy[h][w].rgbtGreen + copy[h][w + 1].rgbtGreen + copy[h + 1][w - 1].rgbtGreen + 
                                       copy[h + 1][w].rgbtGreen + copy[h + 1][w + 1].rgbtGreen) / 9;
                averageBlue = (float)(copy[h - 1][w - 1].rgbtBlue + copy[h - 1][w].rgbtBlue + copy[h - 1][w + 1].rgbtBlue + 
                                      copy[h][w - 1].rgbtBlue + copy[h][w].rgbtBlue + copy[h][w + 1].rgbtBlue + copy[h + 1][w - 1].rgbtBlue + 
                                      copy[h + 1][w].rgbtBlue + copy[h + 1][w + 1].rgbtBlue) / 9;
                averageRed = round(averageRed);
                averageGreen = round(averageGreen);
                averageBlue = round(averageBlue);
                image[h][w].rgbtRed = averageRed;
                image[h][w].rgbtGreen = averageGreen;
                image[h][w].rgbtBlue = averageBlue;
            }
        }
    }
    return;
}