#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int n;
    int i;
    int j;

    do
    {
        n = get_int("Height: ");
    }
    //Ensure n is between 1 and 8
    while ((n <= 0) || (n > 8));

    //For each row
    for(i=0; i < n; i++)
    {
        //For each column
        for(j=0; j < i; j++)
        {
            printf("#");
        }
        printf("\n");
    }

    printf("\n");
}