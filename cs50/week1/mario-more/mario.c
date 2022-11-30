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

    //Leave a space below the entered height
    printf("\n");

    //
    for(i=0; i < n; i++)
    {
        for(j=(i+1); j < n; j++)
        {
            printf(" ");
        }

        for(k=0; k <= i; k++)
        {
            printf("#");
        }
        printf("\n");
    }
    printf("\n");
}