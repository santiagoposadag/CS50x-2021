#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Points assigned to each letter of the alphabet
int POINTS[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};

int compute_score(string word1);

int main(void)
{
    // Get input words from both players
    string word1 = get_string("Player 1: ");
    string word2 = get_string("Player 2: ");

    // Score both words
    int score1 = compute_score(word1);
    int score2 = compute_score(word2);

    // TODO: Print the winner
    if (score1 > score2)
    {
        printf("Player 1 wins!\n");
    }
    else if (score2 > score1)
    {
        printf("Player 2 wins!\n");
    }
    else
    {
        printf("Tie!\n");
    }
}

int compute_score(string word1)
{
    // TODO: Compute and return score for string

    //Here we sotore the argument in a variable so we can manage it as an array
    string word = word1;

    //Here we check what is the spot within the array of point by checking the ASCII value of the character
    int spot = 0;

    //here we sum the points of every letter
    int score = 0;

    int charValue = 0;


    for (int i = 0; (int)word[i] != 0; i++)
    {
        if (isalpha(word[i]))
        {
            if (islower(word[i]))
            {
                charValue = (int)word[i];
                spot = charValue - 97;
                score = score + POINTS[spot];
            }
            else
            {
                charValue = (int)word[i];
                spot = charValue - 65;
                score = score + POINTS[spot];
            }
        }

    }
    return score;
}