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

    printf("Primera letra %c\n", word1[0]);

    printf("Valor de la primera letra %i\n", (int)word1[0]);

    if(isalpha(word1[0])){
        printf("its alphabetic\n");
    }
    else
    {
        printf("is not alphabetic\n");
    }
    for(int i = 0; word1[i] != 0; i++){
        printf("Letra%i: %c\n", i, word1[i]);
    }
}

