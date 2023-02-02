#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int main(void)
{
    // Seed random number generator
    srand(time(0));

    char alleles[] = {'A', 'B', 'O'};

    char parent1[] = {'A', 'B'};
    char parent2[] = {'O', 'A'};

    char child[2];

    // use a random number generator to pick a 1 blood type from each parent
    child[0] = parent1[rand() % 2];
    child[1] = parent2[rand() % 2];

    printf("Child: %c", child[0]);
    printf("%c\n", child[1]);

    char orphan[2];
    orphan[0] = alleles[rand() % 2 + 1];
    orphan[1] = alleles[rand() % 2 + 1];

    printf("Orphan: %c", orphan[0]);
    printf("%c\n", orphan[1]);
}