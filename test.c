#include <cs50.h>
#include <stdio.h>

int main(void) {

    int n;
    int count = 0;

    n = get_int("Enter a Number: ");

    while (n != 0) {
        n = n / 10;
        count ++;
    }

    printf("Number of digits: %i\n", count);

}