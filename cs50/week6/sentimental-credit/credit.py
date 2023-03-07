import sys
import math


def main():

    card = int(input("Card Number: "))              # prompt user for card number

    length = int(math.log10(card)) + 1              # determine card length
    #if valid_length(length) == False:               # check if length valid
        #print("INVALID")
        #sys.exit(1)

    digits = return_list(card)
    













# check for valid card length (13 to 16 digits)
def valid_length(length):
    if (13 <= length <= 16):
        return True
    else:
        return False


# obtain credit card in indexable list form
def return_list(card):
    tmp = list(map(int, str(card)))
    return tmp






main()

