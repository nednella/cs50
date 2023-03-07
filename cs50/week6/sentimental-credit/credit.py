import sys
import math


def main():

    card = int(input("Card Number: "))              # prompt user for card number


    #if valid_Length(card) == False:                 # check if card length valid
        #print("INVALID")
        #sys.exit(1)

    if luhn_checkSum(card) == False:                # check if card number valid as per Luhn's algorithm
        print("INVALID")
        sys.exit(1)


def valid_Length(card):
    length = int(math.log10(card)) + 1              # determine card length
    if (13 <= length <= 16):                        # check for valid card length (13 to 16 digits)
        return True
    else:
        return False


def luhn_checkSum(card):
    digits = list(map(int, str(card)))              # convert credit card digits to an indexable list
    digits.reverse()                                # set the list in reverse

    even_Digits = digits[0::2]                      # obtain list of every 2nd digit starting from the 0th digit
    odd_Digits = digits[1::2]                       # obtain list of every 2nd digit starting from the 1st digit

    luhn_Sum = 0                                    # initialise algorithm sum
    luhn_Sum += sum(even_Digits)

    for d in odd_Digits:
        luhn_Sum += sum(divmod(d * 2, 10))

    if luhn_Sum % 10 == 0:                          # check if luhn sum is a factor of 10
        return True
    else:
        return False


main()