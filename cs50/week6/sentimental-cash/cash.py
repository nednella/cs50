

def main():
    # ask what the customer is owed in change
    change = get_payment()

    # calculate number of quarters to give the customer
    quarters = calc_quarters()

    # calculate number of dimes to give the customer
    dimes = calc_dimes()

    # calculate number of nickels to give the customer
    nickels = calc_dimes()

    # calculate number of pennies to give the customer
    pennies = calc_dimes()

    # sum coins in the change
    coins = quarters + dimes + nickels + pennies


def get_payment():
    while True:
        try:
            change = float(input("Change owed: "))
        except ValueError:
            continue
        else:
            if change >= 0:
                return change


def calc_quarters():



def calc_dimes():



def calc_nickels():



def calc_pennies():



main()