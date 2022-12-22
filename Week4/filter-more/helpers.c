#include "helpers.h"
#include <math.h>
#include <stdio.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
        for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            float avg = (image[i][j].rgbtBlue + image[i][j].rgbtRed + image[i][j].rgbtGreen) / 3;
            avg = roundf(avg);
            image[i][j].rgbtBlue = avg;
            image[i][j].rgbtRed = avg;
            image[i][j].rgbtGreen = avg;
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    typedef struct pic{
        uint8_t red;
        uint8_t green;
        uint8_t blue;
    }pics;
    pics copy[height][width];
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            copy[i][j].red = image[i][j].rgbtRed;
            copy[i][j].green = image[i][j].rgbtGreen;
            copy[i][j].blue = image[i][j].rgbtBlue;
        }
    }
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            image[i][j].rgbtBlue = copy[i][width - j - 1].blue;
            image[i][j].rgbtRed = copy[i][width - j - 1].red;
            image[i][j].rgbtGreen = copy[i][width - j - 1].green;
        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    int strong = 3;
    int holdb = 0;
    int holdr = 0;
    int holdg = 0;
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            for (int grid = i; grid < height &&  grid < i + strong; grid++)
            {
                for (int grid1 = j; grid1 < width && grid1 < j + strong; grid1++)
                {
                    holdb += image[grid][grid1].rgbtBlue;
                    holdr += image[grid][grid1].rgbtRed;
                    holdg += image[grid][grid1].rgbtGreen;
                }
                holdb /= strong;
                holdr /= strong;
                holdg /= strong;
                image[i][j].rgbtBlue = holdb;
                image[i][j].rgbtRed = holdr;
                image[i][j].rgbtGreen = holdg;
                holdb = 0;
                holdr = 0;
                holdg = 0;
            }
        }
    }
    return;
}

// Detect edges
void edges(int height, int width, RGBTRIPLE image[height][width])
{
    typedef struct pic
    {
        uint8_t blue;
        uint8_t red;
        uint8_t green;
    }pics;
    pics copy[height][width];
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            copy[i][j].blue = image[i][j].rgbtBlue;
            copy[i][j].red = image[i][j].rgbtRed;
            copy[i][j].green = image[i][j].rgbtGreen;
        }
    }
    const int Gx[3][3] = {
        {-1, 0, 1},
        {-2, 0, 2},
        {-1, 0, 1}
    };
    const int Gy[3][3] = {
        {-1, -2, -1},
        {0, 0, 0},
        {1, 2, 1}
    };
    for (int i = 1; i < height; i++)
    {
        for (int j = 1; j < width; j++)
        {
            int holdbluex = 0;
            int holdbluey = 0;
            int holdredx = 0;
            int holdredy = 0;
            int holdgreenx = 0;
            int holdgreeny = 0;
            for (int d1 = i - 1, v = 0; d1 < height && d1 < i + 2; d1++, v++)
            {
                for (int d2 = j - 1, t = 0; d2 < width && d2 < j + 2; d2++, t++)
                {
                    holdbluex += copy[d1][d2].blue * Gx[v][t];
                    holdbluey += copy[d1][d2].blue * Gy[v][t];
                    holdredx += copy[d1][d2].red * Gx[v][t];
                    holdredy += copy[d1][d2].red * Gy[v][t];
                    holdgreenx += copy[d1][d2].green * Gx[v][t];
                    holdgreeny += copy[d1][d2].green * Gy[v][t];
                }
            }
            image[i][j].rgbtBlue = sqrt(round((holdbluex * holdbluex) + (holdbluey * holdbluey)));
            image[i][j].rgbtGreen = sqrt(round((holdgreenx * holdgreenx) + (holdbluey * holdgreeny)));
            image[i][j].rgbtRed = sqrt(round((holdredx * holdredx) + (holdredy * holdredy)));
        }
    }
    return;
}
