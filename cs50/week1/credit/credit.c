#include <cs50.h>
#include <stdio.h>

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

        int a = cc % 100;
        printf("%i\n", a);



        //The card number is valid
        //Luhn algorithm check - obtain every 2nd number
        //Create array of 9 elements
        //int n[9]; for (int i = 0; i < 10; i++) n[i]=0; // Fill array with 0

        //Example cc number - 1 2 3 4 5 1 2 3 4 5 1 2 3 4 5 1
        //n[1] = (cc % 100)                    //obtains last 2  numbers - 10
        //n[2] = (cc % 10000)                  //obtains last 4  numbers - 1000
        //n[3] = (cc % 10000000)               //obtains lasr 6  numbers - 100000
        //n[4] = (cc % 100000000)              //obtains last 8  numbers - 10000000
        //n[5] = (cc % 10000000000)            //obtains last 10 numbers - 1000000000
        //n[6] = (cc % 1000000000000)          //obtains last 12 numbers - 100000000000
        //n[7] = (cc % 100000000000000)        //obtains last 14 numbers - 10000000000000
        //n[8] = (cc % 10000000000000000)      //obtains last 16 numbers - 1000000000000000





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