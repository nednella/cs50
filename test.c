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


        long b = (cc % 10000000000000000);//)  / 1000000000000000);
        printf("%li is the result\n", b);
    }
}