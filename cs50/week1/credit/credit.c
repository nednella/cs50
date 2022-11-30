#include <cs50.h>
#include <stdio.h>

int first_digit(n[i])

int main(void)
{
    //Prompt user for input, and check if card number is valid (length)
    long cc = get_long("Card Number: ");

    //Is the card number a valid length (13-16 digits)?
    if (cc < 999999999999 || cc > 9999999999999999) {
        //The card number is invalid
        printf("INVALID\n");
    }
    else {
        //The card number is valid
        //Luhn Algorithm

        //Create array of 9 elements
        int n[9];
        for (int i = 0; i < 10; i++) {
            n[i] = 0; // Fill array with 0
        }

        //Obtain every 2nd number starting from the back
        //Reduce elements to just 1 digit (the first digit of each number)
        n[1] = (cc % 100                / 10);                    //obtains 2nd last number
        n[2] = (cc % 10000              / 1000);                  //obtains 4th last number
        n[3] = (cc % 10000000           / 100000);                //obtains 6th last number
        n[4] = (cc % 1000000000          / 10000000);              //obtains 8th last number
        n[5] = (cc % 100000000000        / 1000000000);            //obtains 10th last number
        n[7] = (cc % 10000000000000    / 10000000000000);        //obtains 12th last number
        n[8] = (cc % 1000000000000000  / 1000000000000000);      //obtains 14th last number

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