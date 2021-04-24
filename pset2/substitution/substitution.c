#include <stdio.h>
#include <cs50.h>
#include <ctype.h>
#include <string.h>

int keyValidation(int argc, string argv[]);
int cipher(string plainText, string key);
int main(int argc, string argv[])
{
    int value = keyValidation(argc, argv);
    if (value == 1)
    {
        return 1;
    }

    string plainText = get_string("plaintext: ");
    value = cipher(plainText, argv[1]);
    return value;
}



int keyValidation(int argc, string argv[])
{
    if (argc == 2)
    {
        //checking key length.
        int length = 0;
        for (int i = 0; argv[1][i] != 0; i++)
        {
            length++;
        }
        if (length != 26)
        {
            printf("the key must have 26 characters\n");
            return 1;
        }
        for (int i = 0; argv[1][i] != 0; i++)
        {
            if (isalpha(argv[1][i]))
            {
            }
            else
            {
                printf("Your key should only contain alphabetic characters\n");
                return 1;
            }

        }

        //I am going to build an array that counts how many times does a letter have apeared, if its more than one
        //the key is invalid.
        int taken[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
        for (int i = 0; argv[1][i] != 0; i++)
        {
            if (islower(argv[1][i]))
            {
                int assign = (int)argv[1][i] - 97;
                taken[assign] = taken[assign] + 1;
            }
            else
            {
                int assign = (int)argv[1][i] - 65;
                taken[assign] = taken[assign] + 1;

            }
        }
        for (int i = 0; i < 26; i++)
        {
            if (taken[i] != 1)
            {
                printf("you shouldnt repeat any letter in your key\n");
                return 1;
            }
        }

    }
    else
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }
    return 0;
}

int cipher(string plainText, string key)
{
    printf("ciphertext: ");
    for (int i = 0; (int)plainText[i] != 0; i++)
    {
        if (isalpha(plainText[i]))
        {
            if (islower(plainText[i]))
            {
                int spot = (int)plainText[i] - 97;
                printf("%c", tolower(key[spot]));
            }
            else
            {
                int spot = (int)plainText[i] - 65;
                printf("%c", toupper(key[spot]));
            }
        }
        else
        {
            printf("%c", plainText[i]);
        }
    }
    printf("\n");
    return 0;
}
