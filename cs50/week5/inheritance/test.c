#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int main(void)
{
    // Seed random number generator
    srand(time(0));
    
    char parent1[] = {'A', 'B'};
    char parent2[] = {'O', 'A'};

    char child[2];

    child[0] = parent1[rand() % 2];
    child[1] = parent2[rand() % 2];

    printf("%c\n", child[0]);
    printf("%c\n", child[1]);

}