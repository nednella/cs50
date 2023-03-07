import sys
import math


def main():

    # prompt user for input
    card = int(input("Card Number: "))           # user input in string form

    digits = (math.log10(card)) + 1
    print(digits)



    #if valid_length(card) == False:         # validate length in string form
        #print("INVALID")
        #sys.exit(1)

    #cc = int(card)                          # convert to integer











# check for valid card length (13 to 16 digits)
def valid_length(card):
    length = math.log10(card) + 1
    if (length < 13 or length > 16):
        return False
    else:
        return True


def get_digit(card, pos):
    return card // 10**n % 10




main()

