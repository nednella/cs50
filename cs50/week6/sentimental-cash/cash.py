

def main():



def get_cents():

    while True:
        try:
            dollars = float(input("Change owed: "))
        except ValueError:
            continue
        else:
            if dollars > 0:
                return dollars




def calc_quarters():



def calc_dimes():



def calc_nickels():



def calc_pennies():



main()