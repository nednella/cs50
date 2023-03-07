import sys
import math


def main():

    card = int(input("Card Number: "))              # prompt user for card number


    #if valid_Length(card) == False:                 # check if length valid
        #print("INVALID")
        #sys.exit(1)

    if luhn_Algorithm(card) == False:                     # check if card number valid
        print("INVALID")
        sys.exit(1)







def valid_Length(card):
    length = int(math.log10(card)) + 1              # determine card length
    if (13 <= length <= 16):                        # check for valid card length (13 to 16 digits)
        return True
    else:
        return False


# obtain credit card in indexable list form



# perform Luhn's algorithm check on the card
def luhn_Algorithm(card):
    digits = list(map(int, str(card)))              # convert credit card digits to an indexable list
    digits.reverse()                                # set the list in reverse

    even_Digits = digits[0::2]                      # obtain list of every 2nd digit starting from the 0th digit
    odd_Digits = digits[1::2]                       # obtain list of every 2nd digit starting from the 1st digit

    print(digits)
    print(odd_Digits)
    print(even_Digits)

    luhn_Sum = 0
    #luhn_Sum += sum(even_Digits)
    #print(luhn_Sum)

    for d in odd_Digits:
        luhn_Sum += sum(divmod(d * 2, 10))
        print(luhn_Sum)
    print(f"Final Value: {luhn_Sum}")

    #print(f"10: {sum(divmod(10,10))}")
    #print(f"12: {sum(divmod(12,10))}")
    #print(f"15: {sum(divmod(15,10))}")
    #print(f"17: {sum(divmod(17,10))}")
    #print(f"19: {sum(divmod(19,10))}")

    #luhn_Sum += sum(sum(divmod(d * 2, 10)) for d in odd_Digits)
    #print(luhn_Sum)

    #for d in odd_Digits:
        #print(f"Odd Digit {d}: {odd_Digits}")

    #for i in range(0, (len(digits) + 1) / 2, 2):
        #print(digits[i])





main()

