import sys
import math


def main():

    card = int(input("Card Number: "))              # prompt user for card number


    #if valid_length(card) == False:                 # check if length valid
        #print("INVALID")
        #sys.exit(1)

    if luhn_algorithm(card) == False:                     # check if card number valid
        print("INVALID")
        sys.exit(1)







def valid_length(card):
    length = int(math.log10(card)) + 1              # determine card length
    if (13 <= length <= 16):                        # check for valid card length (13 to 16 digits)
        return True
    else:
        return False


# obtain credit card in indexable list form
#def return_list(card):
    #tmp = list(map(int, str(card)))
    #return tmp


# perform Luhn's algorithm check on the card
def luhn_algorithm(card):
    card_digits = list(map(int, str(card)))         # convert credit card digits to an indexable list


    
    length = int(math.log10(card)) + 1              # determine card length
    for i in range(length):
        print(card_digits[i])


main()

