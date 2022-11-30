#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int n, i, j, k;

    do
    {
        n = get_int("Height: ");
    }
    //Ensure n is between 1 and 8
    while ((n <= 0) || (n > 8));

    printf("\n");

    //For each row
    for(i=0; i < n; i++)
    {
        //For each column
        for(j=0; j < n; j++)
        {
            printf(" ");
        }

        //For each column
        for(k=0; k <= i; k++)
        {
            printf("#");
        }



        printf("\n");
    }

    printf("\n");
}