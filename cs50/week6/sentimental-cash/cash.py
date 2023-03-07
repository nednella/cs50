

def main():
    # ask what the customer is owed in change
    change = get_change()

    quarters = calc_quarters(change)                # calculate quarters
    change = round(change - (quarters * 0.25), 2)   # update remaining change

    dimes = calc_dimes(change)                      # calculate dimes
    change = round(change - (dimes * 0.1), 2)       # update remaining change


    nickels = calc_nickels(change)                  # calculate nickels
    change = round(change - (nickels * 0.05), 2)    # update remaining change

    pennies = calc_pennies(change)                  # calculate pennies
    change = round(change - (pennies * 0.01), 2)    # update remaining change

    # calculate total coin quantity and print
    coins = quarters + dimes + nickels + pennies
    print(coins)


def get_change():
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