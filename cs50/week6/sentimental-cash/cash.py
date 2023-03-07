

def main():
    # ask what the customer is owed in change
    change = get_payment()

    # calculate number of quarters to give the customer
    quarters = calc_quarters(change)
    print(f"Quarters: {quarters}")
    change = change - (quarters * 0.25)

    # calculate number of dimes to give the customer
    dimes = calc_dimes(change)
    print(f"Dimes: {dimes}")
    change = change - (dimes * 0.1)

    # calculate number of nickels to give the customer
    nickels = calc_nickels(change)
    print(f"Nickels: {nickels}")
    change = change - (nickels * 0.05)

    # calculate number of pennies to give the customer
    pennies = calc_pennies(change)
    change = change - (pennies * 0.01)

    # sum coins in the change
    coins = quarters + dimes + nickels + pennies
    print(coins)


def get_payment():
    while True:
        try:
            change = float(input("Change owed: "))
        except ValueError:
            continue
        else:
            if change >= 0:
                return change


def calc_quarters(change):
    quarters = change / 0.25
    return quarters


def calc_dimes(change):
    dimes = change / 0.1
    return dimes


def calc_nickels(change):
    nickels = change / 0.05
    return nickels


def calc_pennies(change):
    pennies = change / 0.01
    return pennies


main()