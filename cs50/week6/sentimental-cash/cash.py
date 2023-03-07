

def main():
    # ask what the customer is owed in change
    change = get_payment()

    quarters = calc_quarters(change)        # calculate quarters
    print(f"Quarters: {quarters}")
    change = change - (quarters * 0.25)     # update remaining change
    print()

    dimes = calc_dimes(change)              # calculate dimes
    print(f"Dimes: {dimes}")
    change = change - (dimes * 0.1)         # update remaining change

    nickels = calc_nickels(change)          # calculate nickels
    print(f"Nickels: {nickels}")
    change = change - (nickels * 0.05)      # update remaining change

    pennies = calc_pennies(change)          # calculate pennies
    print(f"Pennies: {pennies}")
    change = change - (pennies * 0.01)      # update remaining change

    # calculate total coin quantity and print
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
    quarters = int(change / 0.25)
    return quarters


def calc_dimes(change):
    dimes = int(change / 0.1)
    return dimes


def calc_nickels(change):
    nickels = int(change / 0.05)
    return nickels


def calc_pennies(change):
    pennies = int(change / 0.01)
    return pennies


main()