#include <cs50.h>
#include <stdio.h>

int main(void)
{
    //Prompt user for input, and check if card number is valid (length)
    long cc = get_long("Card Number: ");

    //Is the card number a valid length (13-16 digits)?
    //if (cc < 1000000000000 || cc > 10000000000000000) {
        //The card number is invalid
        //printf("INVALID\n");
    //}
    //else {

        long a = (cc % 100)               / 10;
        //long b = (cc % 10000)             / 1000;
        //long c = (cc % 1000000)           / 100000;
        //long d = (cc % 100000000)         / 10000000;
        //long e = (cc % 10000000000)       / 1000000000;
        //long f = (cc % 1000000000000)     / 100000000000;
        //long g = (cc % 100000000000000)   / 10000000000000;
        //long h = (cc % 10000000000000000) / 1000000000000000;


        printf("%li is the result\n", a);
        //printf("%li is the result\n", b);
        //printf("%li is the result\n", c);
        //printf("%li is the result\n", d);
        //printf("%li is the result\n", e);
        //printf("%li is the result\n", f);
        //printf("%li is the result\n", g);
        //printf("%li is the result\n", h);
    //}
}