import sys
import math


def main():

    card = int(input("Card Number: "))          # prompt user for card number

    if valid_length(card) == False:             # check if valid length
        print("INVALID")
        sys.exit(1)














# check for valid card length (13 to 16 digits)
def valid_length(card):
    length = int(math.log10(card)) + 1
    if (13 <= length <= 16):
        return True
    else:
        return False


# obtain specified digit of the card number
def get_digit(card, pos):
    if card < 10:
        print(card)
    else:
        get_digit()




main()

