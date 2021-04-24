#include <stdio.h>
#include <cs50.h>
#include <ctype.h>
#include <string.h>
#include <math.h>

int main(void)
{
    string text = get_string("Text: ");
//to count every letter word and sentence, but as at the end of the text we dont have a space that is what add into the word
//i start the count from 1.
    int letters = 0;
    int words = 1;
    int sentences = 0;

    for (int i = 0; (int)text[i] != 0; i++)
    {
        if (((int)text[i] >= 65 && (int)text[i] <= 90) || ((int)text[i] >= 97 && (int)text[i] <= 122))
        {
            letters++;
        }
        if ((int)text[i] == 32)
        {
            words++;
        }
        else if ((int)text[i] == 33 || (int)text[i] == 46 || (int)text[i] == 63)
        {
            sentences++;
        }
    }

    //here i convert the integers that i was using, to floats for better accuracy

    float l = ((float)letters / (float)words) * 100.0;
    float s = ((float)sentences / (float)words) * 100.0;

    float index = ((0.0588 * l) - (0.296 * s) - 15.8);
    index = round(index);

    if (index < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (index > 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %i\n", (int)index);
    }

}