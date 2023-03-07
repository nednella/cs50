

def main():



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