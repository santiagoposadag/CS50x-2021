#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

typedef uint8_t BYTE;

int main(int argc, char *argv[])
{
    //Verify if the user inputs its the right one for us to work
    if (argc != 2)
    {
        printf("Usage: ./recover image\n");
        return 1;
    }

    //we open the memory card so we can start reading all the information that its inside.
    FILE *memory_card = fopen(argv[1], "r");

    //Here we verify that we actually could open the mwmory card AKA file.
    if (memory_card == NULL)
    {
        printf("Couldn`t open the memory card");
        return 1;
    }

    //Here we initialice a string were we are going to name all the output files
    char *new_title = malloc(8);
    //counter helps us name correctly the files
    int counter = 0;

    //helps us realice if we have to keep writing to the file or just open a new file
    int currently_writing = 0;

    //Instead of using a boolean data type i used integers 0 that represents that we arent currently writing a new image or 1 if we are currently
    //writing in an image that is already initialiced
    int writing = 0;

    //Buffer is the plave where we are going to allocate the part of the image that we are going to write.

    BYTE buffer[512];
    int fread_return = fread(&buffer, sizeof(BYTE), 512, memory_card);
    printf("Returned value: %i\n", fread_return);

    sprintf(new_title, "%03i.jpg", counter);

    FILE *writeInto = fopen(new_title, "w");

    while (fread_return == 512)
    {
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0)
        {
            if (counter != currently_writing)
            {
                fclose(writeInto);
                currently_writing = counter;
                sprintf(new_title, "%03i.jpg", counter);
                writeInto = fopen(new_title, "w");
                writing = 1;
                counter++;

            }
            else
            {
                writing = 1;
                counter++;
            }
            fwrite(&buffer, sizeof(BYTE), 512, writeInto);
            fread_return = fread(&buffer, sizeof(BYTE), 512, memory_card);
        }
        else
        {
            if (writing == 1)
            {
                fwrite(&buffer, sizeof(BYTE), 512, writeInto);
            }
            fread_return = fread(&buffer, sizeof(BYTE), 512, memory_card);
        }
    }
    free(new_title);
    fclose(memory_card);
    fclose(writeInto);

}