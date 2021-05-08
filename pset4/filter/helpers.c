#include "helpers.h"
#include <math.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            float average;
            average = (image[i][j].rgbtBlue + image[i][j].rgbtRed + image[i][j].rgbtGreen) / 3.0;
            image[i][j].rgbtBlue = (int)round(average);
            image[i][j].rgbtRed = (int)round(average);
            image[i][j].rgbtGreen = (int)round(average);
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
            float sepiaRed = 0.393 * image[i][j].rgbtRed + 0.769 * image[i][j].rgbtGreen + 0.189 * (float)image[i][j].rgbtBlue;
            if (sepiaRed > 255)
            {
                sepiaRed = 255.0;
            }
            float sepiaGreen = 0.349 * image[i][j].rgbtRed + 0.686 * image[i][j].rgbtGreen + 0.168 * (float)image[i][j].rgbtBlue;
            if (sepiaGreen > 255)
            {
                sepiaGreen = 255;
            }
            float sepiaBlue = 0.272 * image[i][j].rgbtRed + 0.534 * image[i][j].rgbtGreen + 0.131 * (float)image[i][j].rgbtBlue;
            if (sepiaBlue > 255)
            {
                sepiaBlue = 255;
            }

            image[i][j].rgbtBlue = (int)round(sepiaBlue);
            image[i][j].rgbtRed = (int)round(sepiaRed);
            image[i][j].rgbtGreen = (int)round(sepiaGreen);
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    int temporalBlue;
    int temporalRed;
    int temporalGeen;

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width / 2; j++)
        {
            temporalGeen = image[i][j].rgbtGreen;
            temporalRed = image[i][j].rgbtRed;
            temporalBlue = image[i][j].rgbtBlue;

            image[i][j].rgbtGreen = image[i][width - 1 - j].rgbtGreen;
            image[i][j].rgbtRed = image[i][width - 1 - j].rgbtRed;
            image[i][j].rgbtBlue = image[i][width - 1 - j].rgbtBlue;

            image[i][width - 1 - j].rgbtBlue = temporalBlue;
            image[i][width - 1 - j].rgbtRed = temporalRed;
            image[i][width - 1 - j].rgbtGreen = temporalGeen;
        }
    }

    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE temporal_image[height][width];
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            temporal_image[i][j].rgbtBlue = image[i][j].rgbtBlue;
            temporal_image[i][j].rgbtRed = image[i][j].rgbtRed;
            temporal_image[i][j].rgbtGreen = image[i][j].rgbtGreen;
        }
    }

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            if (i == 0)
            {
                if (j == 0)
                {
                    image[i][j].rgbtGreen = (int)round((temporal_image[i][j].rgbtGreen + temporal_image[i + 1][j].rgbtGreen + temporal_image[i]
                                                        [j + 1].rgbtGreen + temporal_image[i + 1][j + 1].rgbtGreen) / 4.0);

                    image[i][j].rgbtRed = (int)round((temporal_image[i][j].rgbtRed + temporal_image[i + 1][j].rgbtRed + temporal_image[i][j + 1]
                                                      .rgbtRed + temporal_image[i + 1][j + 1].rgbtRed) / 4.0);

                    image[i][j].rgbtBlue = (int)round((temporal_image[i][j].rgbtBlue + temporal_image[i + 1][j].rgbtBlue + temporal_image[i]
                                                       [j + 1].rgbtBlue + temporal_image[i + 1][j + 1].rgbtBlue) / 4.0);
                }
                else if (j == (width - 1))
                {
                    image[i][j].rgbtGreen = (int)round((temporal_image[i][j].rgbtGreen + temporal_image[i + 1][j].rgbtGreen + temporal_image[i]
                                                        [j - 1].rgbtGreen + temporal_image[i + 1][j - 1].rgbtGreen) / 4.0);

                    image[i][j].rgbtRed = (int)round((temporal_image[i][j].rgbtRed + temporal_image[i + 1][j].rgbtRed + temporal_image[i]
                                                      [j - 1].rgbtRed + temporal_image[i + 1][j - 1].rgbtRed) / 4.0);

                    image[i][j].rgbtBlue = (int)round((temporal_image[i][j].rgbtBlue + temporal_image[i + 1][j].rgbtBlue + temporal_image[i]
                                                       [j - 1].rgbtBlue + temporal_image[i + 1][j - 1].rgbtBlue) / 4.0);
                }
                else
                {
                    image[i][j].rgbtGreen = (int)round((temporal_image[i][j].rgbtGreen + temporal_image[i + 1][j].rgbtGreen + temporal_image[i]
                                                        [j - 1].rgbtGreen + temporal_image[i][j + 1].rgbtGreen + temporal_image[i + 1][j - 1]
                                                        .rgbtGreen + temporal_image[i + 1][j + 1].rgbtGreen) / 6.0);

                    image[i][j].rgbtRed = (int)round((temporal_image[i][j].rgbtRed + temporal_image[i + 1][j].rgbtRed + temporal_image[i]
                                                      [j - 1].rgbtRed + temporal_image[i][j + 1].rgbtRed + temporal_image[i + 1][j - 1].rgbtRed
                                                      + temporal_image[i + 1][j + 1].rgbtRed) / 6.0);

                    image[i][j].rgbtBlue = (int)round((temporal_image[i][j].rgbtBlue + temporal_image[i + 1][j].rgbtBlue + temporal_image[i]
                                                       [j - 1].rgbtBlue + temporal_image[i][j + 1].rgbtBlue + temporal_image[i + 1][j - 1].rgbtBlue
                                                       + temporal_image[i + 1][j + 1].rgbtBlue) / 6.0);
                }
            }
            else if (i == (height - 1))
            {
                if (j == 0)
                {
                    image[i][j].rgbtGreen = (int)round((temporal_image[i][j].rgbtGreen + temporal_image[i - 1][j].rgbtGreen + temporal_image[i]
                                                        [j + 1].rgbtGreen + temporal_image[i - 1][j + 1].rgbtGreen) / 4.0);
                    image[i][j].rgbtRed = (int)round((temporal_image[i][j].rgbtRed + temporal_image[i - 1][j].rgbtRed + temporal_image[i]
                                                      [j + 1].rgbtRed + temporal_image[i - 1][j + 1].rgbtRed) / 4.0);
                    image[i][j].rgbtBlue = (int)round((temporal_image[i][j].rgbtBlue + temporal_image[i - 1][j].rgbtBlue + temporal_image[i]
                                                       [j + 1].rgbtBlue + temporal_image[i - 1][j + 1].rgbtBlue) / 4.0);

                }
                else if (j == (width - 1))
                {
                    image[i][j].rgbtGreen = (int)round((temporal_image[i][j].rgbtGreen + temporal_image[i - 1][j].rgbtGreen + temporal_image[i]
                                                        [j - 1].rgbtGreen + temporal_image[i - 1][j - 1].rgbtGreen) / 4.0);
                    image[i][j].rgbtRed = (int)round((temporal_image[i][j].rgbtRed + temporal_image[i - 1][j].rgbtRed + temporal_image[i][j - 1]
                                                      .rgbtRed + temporal_image[i - 1][j - 1].rgbtRed) / 4.0);
                    image[i][j].rgbtBlue = (int)round((temporal_image[i][j].rgbtBlue + temporal_image[i - 1][j].rgbtBlue + temporal_image[i]
                                                       [j - 1].rgbtBlue + temporal_image[i - 1][j - 1].rgbtBlue) / 4.0);

                }
                else
                {
                    image[i][j].rgbtGreen = (int)round((temporal_image[i][j].rgbtGreen + temporal_image[i - 1][j].rgbtGreen + temporal_image[i]
                                                        [j - 1].rgbtGreen + temporal_image[i][j + 1].rgbtGreen + temporal_image[i - 1][j - 1]
                                                        .rgbtGreen + temporal_image[i - 1][j + 1].rgbtGreen) / 6.0);

                    image[i][j].rgbtRed = (int)round((temporal_image[i][j].rgbtRed + temporal_image[i - 1][j].rgbtRed + temporal_image[i]
                                                      [j - 1].rgbtRed + temporal_image[i][j + 1].rgbtRed + temporal_image[i - 1][j - 1].rgbtRed
                                                      + temporal_image[i - 1][j + 1].rgbtRed) / 6.0);

                    image[i][j].rgbtBlue = (int)round((temporal_image[i][j].rgbtBlue + temporal_image[i - 1][j].rgbtBlue + temporal_image[i]
                                                       [j - 1].rgbtBlue + temporal_image[i][j + 1].rgbtBlue + temporal_image[i - 1][j - 1].rgbtBlue
                                                       + temporal_image[i - 1][j + 1].rgbtBlue) / 6.0);

                }

            }
            else if (j == 0)
            {
                image[i][j].rgbtGreen = (int)round((temporal_image[i][j].rgbtGreen + temporal_image[i - 1][j].rgbtGreen + temporal_image[i + 1]
                                                    [j].rgbtGreen + temporal_image[i][j + 1].rgbtGreen + temporal_image[i - 1][j + 1].
                                                    rgbtGreen + temporal_image[i + 1][j + 1].rgbtGreen) / 6.0);

                image[i][j].rgbtRed = (int)round((temporal_image[i][j].rgbtRed + temporal_image[i - 1][j].rgbtRed + temporal_image[i + 1][j]
                                                  .rgbtRed + temporal_image[i][j + 1].rgbtRed + temporal_image[i - 1][j + 1].rgbtRed +
                                                  temporal_image[i + 1][j + 1].rgbtRed) / 6.0);

                image[i][j].rgbtBlue = (int)round((temporal_image[i][j].rgbtBlue + temporal_image[i - 1][j].rgbtBlue + temporal_image[i + 1][j]
                                                   .rgbtBlue + temporal_image[i][j + 1].rgbtBlue + temporal_image[i - 1][j + 1].rgbtBlue +
                                                   temporal_image[i + 1][j + 1].rgbtBlue) / 6.0);

            }
            else if (j == (width - 1))
            {
                image[i][j].rgbtGreen = (int)round((temporal_image[i][j].rgbtGreen + temporal_image[i - 1][j].rgbtGreen + temporal_image[i + 1]
                                                    [j].rgbtGreen + temporal_image[i][j - 1].rgbtGreen + temporal_image[i - 1][j - 1].rgbtGreen +
                                                    temporal_image[i + 1][j - 1].rgbtGreen) / 6.0);
                image[i][j].rgbtRed = (int)round((temporal_image[i][j].rgbtRed + temporal_image[i - 1][j].rgbtRed + temporal_image[i + 1][j]
                                                  .rgbtRed + temporal_image[i][j - 1].rgbtRed + temporal_image[i - 1][j - 1].rgbtRed +
                                                  temporal_image[i + 1][j - 1].rgbtRed) / 6.0);
                image[i][j].rgbtBlue = (int)round((temporal_image[i][j].rgbtBlue + temporal_image[i - 1][j].rgbtBlue + temporal_image[i + 1]
                                                   [j].rgbtBlue + temporal_image[i][j - 1].rgbtBlue + temporal_image[i - 1][j - 1].rgbtBlue +
                                                   temporal_image[i + 1][j - 1].rgbtBlue) / 6.0);

            }
            else
            {
                image[i][j].rgbtGreen = (int)round((temporal_image[i][j].rgbtGreen + temporal_image[i - 1][j].rgbtGreen + temporal_image[i + 1][j]
                                                    .rgbtGreen + temporal_image[i][j - 1].rgbtGreen + temporal_image[i][j + 1].rgbtGreen + temporal_image[i - 1]
                                                    [j - 1].rgbtGreen + temporal_image[i - 1][j + 1].rgbtGreen + temporal_image[i + 1][j - 1].rgbtGreen +
                                                    temporal_image[i + 1][j + 1].rgbtGreen) / 9.0);

                image[i][j].rgbtRed = (int)round((temporal_image[i][j].rgbtRed + temporal_image[i - 1][j].rgbtRed + temporal_image[i + 1][j]
                                                  .rgbtRed + temporal_image[i][j - 1].rgbtRed + temporal_image[i][j + 1].rgbtRed + temporal_image[i - 1]
                                                  [j - 1].rgbtRed + temporal_image[i - 1][j + 1].rgbtRed + temporal_image[i + 1][j - 1].rgbtRed +
                                                  temporal_image[i + 1][j + 1].rgbtRed) / 9.0);

                image[i][j].rgbtBlue = (int)round((temporal_image[i][j].rgbtBlue + temporal_image[i - 1][j].rgbtBlue + temporal_image[i + 1]
                                                   [j].rgbtBlue + temporal_image[i][j - 1].rgbtBlue + temporal_image[i][j + 1].rgbtBlue +
                                                   temporal_image[i - 1][j - 1].rgbtBlue + temporal_image[i - 1][j + 1].rgbtBlue +
                                                   temporal_image[i + 1][j - 1].rgbtBlue + temporal_image[i + 1][j + 1].rgbtBlue) / 9.0);
            }
        }
    }



    return;
}
