#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include <string.h>
#include <ctype.h>

void print(char* word);

int main(void)
{
    FILE* file = fopen("dictionaries/small", "r");
    if (file == NULL)
    {
        return 1;
    }

    char word[20];


    while (fscanf(file, "%s", word) != EOF)
    {
        print(word);
    }


    printf("Hola\n");
}


void print(char* word)
{
    printf("%s\n", word);
}