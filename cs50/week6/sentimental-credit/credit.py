import sys


def main():

    card = int(input("Card Number: "))              # prompt user for card number
    card = list(map(int, str(card)))                # convert credit card digits to an indexable list


    if valid_Length(card) == False or luhn_checkSum(card) == False:     # check if card valid
        print("INVALID")
        sys.exit(1)

    if amex(card) == True:
        print("AMEX")
        sys.exit(0)

    elif visa(card) == True:
        print("AMEX")
        sys.exit(0)

    elif mastercard(card) == True:
        print("AMEX")
        sys.exit(0)
    else:
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
    nums = int(str(card[0]) + str(card[1]))                 # concatenate first two digits of the card
    if len(card) == 15 and (nums == 34 or nums == 37):      # check for AMEX card properties
        return True
    else:
        return False


def visa(card):
    if card[0] == 4 and (len(card) == 13 or len(card) == 16):   # check for VISA card properties
        return True
    else:
        return False


def mastercard(card)
    nums = int(str(card[0]) + str(card[1]))                 # concatenate first two digits of the card
    if len(card) == 16 and (nums == 51 or nums == 52 or nums == 53 or nums == 54 or nums == 55)     # check for Mastercard properties


main()