#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int n;

    do
    {
        n = get_int("Height: ");
    }
    //Ensure n is between 1 and 8
    while ((n <= 0) || (n > 8));

    int i;

    //For each row
    for(i=0; i < n; i++)
    {
        //For each column
        int j;

        for(j=0; j < n; j++)
        {
            printf("#");
        }

        // Move to the next row
        printf("\n");

    }
}