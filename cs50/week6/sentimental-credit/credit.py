import sys
import math


def main():

    card = int(input("Card Number: "))              # prompt user for card number
    card = list(map(int, str(card)))                # convert credit card digits to an indexable list

    #if valid_Length(card) == False:                 # check if card length valid
        #print("INVALID")
        #sys.exit(1)

    if luhn_checkSum(card) == False:                # check if card number valid as per Luhn's algorithm
        print("INVALID")
        sys.exit(1)







def valid_Length(card):
    if (13 <= len(card) <= 16):                     # check for valid card length (13 to 16 digits)
        return True
    else:
        return False


def luhn_checkSum(card):
    reverse = card[::-1]                            # reverse the indexable list of credit card digits

    even_Digits = reverse[0::2]                     # obtain list of every 2nd digit starting from the 0th digit
    odd_Digits = reverse[1::2]                      # obtain list of every 2nd digit starting from the 1st digit

    luhn_Sum = 0                                    # initialise algorithm sum
    luhn_Sum += sum(even_Digits)

    for d in odd_Digits:
        luhn_Sum += sum(divmod(d * 2, 10))

    if luhn_Sum % 10 == 0:                          # check if luhn sum is a factor of 10
        return True
    else:
        return False



def amex(card):

    nums = int(str(card[0]) + str(card[1]))

    if len(card) == 15 and (nums == 34 or nums == 37)

        if ((card[0] == 3 and card[1] == 4) or (card[0] == 3 and card[1] == 7)):  ##################### fix this
            return True
    else:
        return False


def visa(card):
    if len(card) == 13 and card[0] == 4:
        return True
    elif len(card) == 16 and card[0] == 4:
        return True
    else:
        return False


#def mastercard(card)



main()