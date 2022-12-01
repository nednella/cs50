#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // Prompt user for input, and check if card number is valid (length)
    long cc = get_long("Card Number: ");

    // Is the card number a valid length (13-16 digits)?
    if (cc < 1000000000000 || cc > 10000000000000000) {
        // The card number is an invalid length
        printf("INVALID\n");
    }
    else {
        // The card number is a valid length

        // Obtain every individual card number, back -> front
        int n16 = (cc % 10000000000000000) / 1000000000000000;  // 16th number from the back
        int n15 = (cc % 1000000000000000)  / 100000000000000;   // 15th number from the back
        int n14 = (cc % 100000000000000)   / 10000000000000;    // 14th number from the back
        int n13 = (cc % 10000000000000)    / 1000000000000;     // 13th number from the back
        int n12 = (cc % 1000000000000)     / 100000000000;      // 12th number from the back
        int n11 = (cc % 100000000000)      / 10000000000;       // 11th number from the back
        int n10 = (cc % 10000000000)       / 1000000000;        // 10th number from the back
        int n9  = (cc % 1000000000)        / 100000000;         // 9th number from the back
        int n8  = (cc % 100000000)         / 10000000;          // 8th number from the back
        int n7  = (cc % 10000000)          / 1000000;           // 7th number from the back
        int n6  = (cc % 1000000)           / 100000;            // 6th number from the back
        int n5  = (cc % 100000)            / 10000;             // 5th number from the back
        int n4  = (cc % 10000)             / 1000;              // 4th number from the back
        int n3  = (cc % 1000)              / 100;               // 3rd number from the back
        int n2  = (cc % 100)               / 10;                // 2nd number from the back
        int n1  = (cc % 10)                / 1;                 // 1st number from the back

        // Luhn Algorithm
        // (1a) Multiply every 2nd number from the back by 2

        int m1 = n2 * 2;
        int m2 = n4 * 2;
        int m3 = n6 * 2;
        int m4 = n8 * 2;
        int m5 = n10 * 2;
        int m6 = n12 * 2;
        int m7 = n14 * 2;
        int m8 = n16 * 2;

        // (1b) Add together 1st and 2nd digits of the mX integers (some may be > 9)

        int mm1 = ((m1 % 100) / 10) + (m1 % 10);                // mm1 = 1st number of m1 + 2nd number of m1, etc.
        int mm2 = ((m2 % 100) / 10) + (m2 % 10);
        int mm3 = ((m3 % 100) / 10) + (m3 % 10);                // Remember, int doesn't store decimals, so although 15 / 10 = 1.5, int only stores 1!
        int mm4 = ((m4 % 100) / 10) + (m4 % 10);
        int mm5 = ((m5 % 100) / 10) + (m5 % 10);
        int mm6 = ((m6 % 100) / 10) + (m6 % 10);
        int mm7 = ((m7 % 100) / 10) + (m7 % 10);
        int mm8 = ((m8 % 100) / 10) + (m8 % 10);

        int sum_pt1 = mm1 + mm2 + mm3 + mm4 + mm5 + mm6 + mm7 + mm8;

        // (2) Add together numbers that weren't multiplied by 2 in (1a)

        int sum_pt2 = n15 + n13 + n11 + n9 + n7 + n5 + n3 + n1;

        // (3) Add together the two halves above

        int_sum = sum_pt1 + sum_pt2;

        // (4) Validate that the last number of int_sum is a 0
        if (int_sum % 10 != 0) {
            // The card number itself is not valid as per the Luhn Algorithm
            printf("INVALID\n");
        }
        else {
            // Check for exact card number length
            int n;
            int count = 0;

            while (n != 0) {
                n = n / 10;
                count++;
            }

            if (count == 15) {
                printf("AMEX");
            }
            else if ()


            // If length == 15, card is AMEX

            // If length != 15, card is Mastercard or VISA

            // If first card number is 4, card is VISA

            // Else, card is Mastercard





        }




















    //Test Card Numbers from PayPal

    //AMEX
    //378282246310005
    //371449635398431

    //Mastercard
    //2221000000000009
    //2223000048400011
    //2223016768739313
    //5555555555554444
    //5105105105105100
    //5199999999999991
    //5299999999999990

    //VISA
    //4111111111111111
    //4012888888881881
    //4222222222222
    //4999991111111113
    //4999992222222229
}