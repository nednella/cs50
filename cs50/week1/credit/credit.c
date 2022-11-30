#include <cs50.h>
#include <stdio.h>

int main(void)
{
    //Prompt user for input, and check if card number is valid (length)
    long cn; //card number

    do {
        cn = get_long("Card Number: ");
    }
    while (cn < 999999999999 || cn > 9999999999999999);

    printf("Success\n");




    //Perform CHECKSUM - is the card number valid?
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