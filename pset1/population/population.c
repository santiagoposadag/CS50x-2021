#include <cs50.h>
#include <stdio.h>
#include <cs50.h>

int main(void)
{
    // TODO: Prompt for start size
    float start = 0;
    start = get_float("What is the starting size of the population? ");
    while (start < 9)
    {
        start = get_float("What is the starting size of the population? ");
    }

    // TODO: Prompt for end size
    float end = 0;
    end = get_float("What is the ending size of the population? ");
    while (end < start)
    {
        end = get_float("What is the ending size of the population? ");
    }

    // TODO: Calculate number of years until we reach threshold
    int aumento = 0;
    int i = 0;
    for (i = 1; start < end; i++)
    {
        aumento = (((int)start / 3) - ((int)start / 4));
        start = start + aumento;
    }
    i = i - 1;


    // TODO: Print number of years
    printf("Years: %i\n", i);
}