import sys


def main()

    # prompt user for input
    card = input("Card Number: ")

    if valid_length(card) == False:
        print("INVALID")
        sys.exit(1)

    









# check for valid length (13 to 16 digits)
def valid_length(card)
    if (len(card) < 13 or len(card) > 16):
        return False
    else:
        return True

main()

