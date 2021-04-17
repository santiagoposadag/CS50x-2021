#include <stdio.h>
#include <cs50.h>

int main(void)
{
    //prompt the user to choose de hight.
    int hight = 0;
    hight = get_int("What is the hight that you want between 1 and 8? ");

    while (hight < 1 || hight > 8)
    {
        hight = get_int("What is the hight that you want between 1 and 8? ");
    }
    //hay que crear una variable que se llame 'whites' para saber cuantos espacios en blanco hay que imprimir e igual 'hash',
    //esto va atener un contador que es lo que le va a permitir salir de la fila para el siguiente espacio
    //se le incremetna uno a hash y se le quita uno a whites.
    //hasta que white sea cero.

    //as we have two sides of the piramid one starting with spaces in this instance called 'whites' and the other side starting with 'hashes'
    //i give the problem a side variable for the program to know what is the side that is being buld

    int lado = 1;
    int whites = hight - 1;
    int hash = hight - (hight - 1);

    for (int fila = 1; fila <= (hight * 2); fila++)
    {
        if (lado == 1)
        {
            for (int lado11 = 1; lado11 <= whites; lado11++)
            {
                printf(" ");
            }

            for (int lado12 = 1; lado12 <= hash; lado12++)
            {
                printf("#");

            }
            lado = 2;
            printf("  ");

        }
        else
        {
            for (int lado21 = 1; lado21 <= hash; lado21++)
            {
                printf("#");

            }
            lado = 1;
            printf("\n");
            whites = whites - 1;
            hash = hash + 1;
        }
    }


}