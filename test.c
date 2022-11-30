#include <cs50.h>
#include <stdio.h>

int main(void)
{
    //Prompt user for input, and check if card number is valid (length)
    long cc = get_long("Card Number: ");

    //Is the card number a valid length (13-16 digits)?
    if (cc < 1000000000000 || cc > 10000000000000000) {
        //The card number is invalid
        printf("INVALID\n");
    }
    else {

        int n16  = (cc % 10000000000000000) / 1000000000000000;
        int n15  = (cc % 1000000000000000)  / 100000000000000;
        int n14  = (cc % 100000000000000)   / 10000000000000;
        int n13  = (cc % 10000000000000)    / 1000000000000;
        int n12  = (cc % 1000000000000)     / 100000000000;
        int n11  = (cc % 100000000000)      / 10000000000;
        int n10  = (cc % 10000000000)       / 1000000000;
        int n9  = (cc % 1000000000)        / 100000000;
        int n8  = (cc % 100000000)         / 10000000;
        int n7 = (cc % 10000000)          / 1000000;
        int n6 = (cc % 1000000)           / 100000;
        int n5 = (cc % 100000)            / 10000;
        int n4 = (cc % 10000)             / 1000;
        int n3 = (cc % 1000)              / 100;
        int n2 = (cc % 100)               / 10;
        int n1 = (cc % 10)                / 1;


        printf("%i is 16th digit from the back\n", n16);
        printf("%i is 15th digit from the back\n", n15);
        printf("%i is 14th digit from the back\n", n14);
        printf("%i is 13th digit from the back\n", n13);
        printf("%i is 12th digit from the back\n", n12);
        printf("%i is 11th digit from the back\n", n11);
        printf("%i is 10th digit from the back\n", n10);
        printf("%i is 9th digit from the back\n", n9);
        printf("%i is 8th digit from the back\n", n8);
        printf("%i is 7th digit from the back\n", n7);
        printf("%i is 6th digit from the back\n", n6);
        printf("%i is 5th digit from the back\n", n5);
        printf("%i is 4th digit from the back\n", n4);
        printf("%i is 3rd digit from the back\n", n3);
        printf("%i is 2nd digit from the back\n", n2);
        printf("%i is 1st digit from the back\n", n1);


    }
}