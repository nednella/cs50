#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int n, i, j, k, l;

    do
    {
        n = get_int("Height: ");
    }
    //Ensure n is between 1 and 8
    while ((n <= 0) || (n > 8));




    for (i = 0; i < n; i++)
    {
        //Code to produce right-aligned triangle
        for (j = (i+1); j < n; j++)
        {
            printf(" ");
        }

        for (k = 0; k <= i; k++)
        {
            printf("#");
        }

        //Space between triangles
        printf("  ");

        //Code to produce left-aligned triangle
        for (l = 0; l <= i; l++)
        {
            printf("#");
        }


        printf("\n");
    }




}