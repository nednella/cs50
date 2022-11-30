#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // Prompt user for input, and check if card number is valid (length)
    long cc = get_long("Card Number: ");

    // Is the card number a valid length (13-16 digits)?
    if (cc < 1000000000000 || cc > 10000000000000000) {
        // The card number is invalid
        printf("INVALID\n");
    }
    else {
        // The card number is valid

        // Luhn Algorithm

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



        //create rray of 9 elements





        int n[9];

        for (int i = 0; i < 10; i++) {
            n[i] = 0; // Fill array with 0
        }

        //obtain every 2nd number starting from the back
            //set element equal to last X numbers
            //reduce element to just the 1st digit of the last X numbers
        n[1] = (cc % 100)               / 10;               //obtains 2nd last number
        n[2] = (cc % 10000)             / 1000;             //obtains 4th last number
        n[3] = (cc % 1000000)           / 100000;           //obtains 6th last number
        n[4] = (cc % 100000000)         / 10000000;         //obtains 8th last number
        n[5] = (cc % 10000000000)       / 1000000000;       //obtains 10th last number
        n[6] = (cc % 1000000000000)     / 100000000000;     //obtains 12th last number
        n[7] = (cc % 100000000000000)   / 10000000000000;   //obtains 14th last number
        n[8] = (cc % 10000000000000000) / 1000000000000000; //obtains 16th last number

        //Multiply every 2nd number by 2
        int d[9];

        for (int d = 0; d < 10; d++) {
            d[i] = 0; //Fill aray with 0
        }

        d[1] = (n[1] * 2);
        d[2] = (n[2] * 2);
        d[3] = (n[3] * 2);
        d[4] = (n[4] * 2);
        d[5] = (n[5] * 2);
        d[6] = (n[6] * 2);
        d[7] = (n[7] * 2);
        d[8] = (n[8] * 2);

        //


        m[1] = first_digit(d[1])


        //printf("Success\n");






    }




    //checksum( )

    //If invalid
    //printf("INVALID\n");

    //If valid
    //Check for card length and 2 initial card digits




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