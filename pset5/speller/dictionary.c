// Implements a dictionary's functionality

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include <string.h>
#include <ctype.h>

#include "dictionary.h"

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
}
node;

// Number of buckets in hash table
const unsigned int N = 27;

int counter = 0;

unsigned int hash(const char *word);

// Hash table
node *table[N];

// Returns true if word is in dictionary, else false
bool check(const char *word)
{
    // TODO
    int index = hash(word);

    for (node *ite = table[index]; ite != NULL; ite = ite->next)
    {
        if (strcasecmp(ite->word, word) == 0)
        {
            return true;
        }
    }


    return false;
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    // TODO
    if (isupper(word[0]))
    {
        int value = (int)word[0];
        value = value - 65;
        return value;
    }
    else if (islower(word[0]))
    {
        int value = (int)word[0];
        value = value - 97;
        return value;
    }


    return 26;
}

// Loads dictionary into memory, returning true if successful, else false
bool load(const char *dictionary)
{
    // TODO
    FILE *file = fopen(dictionary, "r");
    if (file == NULL)
    {
        printf("Couldnt open the file");
        return false;
    }

    char word[LENGTH + 1];

    while (fscanf(file, "%s", word) != EOF)
    {
        int index = hash(word);
        node *n = malloc(sizeof(node));
        strcpy(n->word, word);
        n->next = NULL;

        node *tmp = NULL;
        tmp = table[index];

        table[index] = n;

        table[index]->next = tmp;

        counter++;
    }

    fclose(file);
    return true;
}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    // TODO
    return counter;
}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    // TODO
    int counter2 = 0;
    for (int i = 0; i < N; i++)
    {
        node *tmp = table[i];

        while (tmp != NULL)
        {
            node *toFree = NULL;
            toFree = tmp;
            tmp = tmp->next;
            free(toFree);
        }
        counter2++;
    }

    if (counter2 == N)
    {
        return true;
    }
    else
    {
        printf("we are having problems unloading");
        return false;
    }

}
