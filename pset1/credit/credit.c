#include <stdio.h>
#include <cs50.h>

int main(void)
{
    long creditCard = get_long("What is your card number? ");

    //we are trying to find out how many digits does this card has
    float length = 0;

    //the variable message is the one that is going to be printed at the end.
    bool message = true;
    string message1 = "";
    if (creditCard >= 1000000000000 && creditCard < 10000000000000)
    {
        length = 13;
    }
    else if (creditCard >= 100000000000000 && creditCard < 1000000000000000)
    {
        length = 15;
    }
    else if (creditCard >= 1000000000000000 && creditCard < 10000000000000000)
    {
        length = 16;
    }
    else
    {
        message = false;
    }

    if (message != false)
    {
        // this are the numbers that arent going to be multiplied by 2
        long sum1 = 0;
        //this is the sum of the numbers that are going to be multiplied by two
        long sum2 = 0;
        // to know how many times we have to do the process
        int counter = 1;
        //in order for us to separate the numbers
        long modulus = 10;
        long divisor = 1;
        //result after the algorithm.
        long result = 0;
        // numero actual con el que estamos trabajando
        long actual = 0;

        for (counter = 1; counter <= length; counter++)
        {
            actual = ((creditCard % modulus) / divisor);
            if (counter % 2 == 0)
            {
                actual = actual * 2;
                if (actual >= 10)
                {
                    sum2 = sum2 + actual / 10 + actual % 10;
                }
                else
                {
                    sum2 = sum2 + actual;
                }
            }
            else
            {
                sum1 = sum1 + actual;
            }
            modulus = modulus * 10;
            divisor = divisor * 10;
        }

        //here we did the Luhn´s algorithm in order to validate if the credit card number was valid.

        result = sum1 + sum2;

        //Here we are cheking if the las number is 0

        if (result % 10 != 0)
        {
            message = false;
        }

        //Here we validate the starting numbers.
        else
        {
            long startingNumber = 0;
            if (length == 13)
            {
                startingNumber = creditCard / 1000000000000;
                if (startingNumber == 4)
                {
                    message1 = "VISA";
                }
                else
                {
                    message = false;
                }
            }
            else if (length == 15)
            {
                startingNumber = creditCard / 10000000000000;
                if (startingNumber == 34 || startingNumber == 37)
                {
                    message1 = "AMEX";
                }
                else
                {
                    message = false;
                }
            }
            else if (length == 16)
            {
                startingNumber = creditCard / 1000000000000000;
                if (startingNumber == 4)
                {
                    message1 = "VISA";
                }
                else if (length == 16)
                {
                    startingNumber = creditCard / 100000000000000;
                    if (startingNumber == 51 || startingNumber == 52 || startingNumber == 53 || startingNumber == 54 || startingNumber == 55)
                    {
                        message1 = "MASTERCARD";
                    }
                    else
                    {
                        message = false;
                    }
                }
            }
        }

    }
    if (message == true)
    {
        printf("%s\n", message1);
    }
    else
    {
        printf("INVALID\n");
    }

}