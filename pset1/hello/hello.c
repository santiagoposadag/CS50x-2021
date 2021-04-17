#include <stdio.h>
#include <cs50.h>

int main(void)
{
    //Getting name of the user to personilize the answer.
    string name = get_string("What is your name? ");
    printf("hello, %s\n", name);
}