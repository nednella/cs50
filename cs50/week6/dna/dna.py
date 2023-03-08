import csv
import sys


def main():

    # TODO: Check for command-line usage
    #if len(sys.argv) != 3:
        #sys.exit("USAGE: python dna.py [data.csv] [sequence.txt]")



    # TODO: Read database file into a variable
    dna_database = []

    with open("databases/small.csv", "r") as file:                           #sys.argv[1]
        db_reader = csv.DictReader(file)
        for row in db_reader:
            name = row['name']
            agatc = int(row['AGATC'])
            aatg = int(row['AATG'])
            tatc = int(row['TATC'])
            dna_database.append({'Name': name, 'AGATC': agatc, 'AATG': aatg, 'TATC': tatc})

    #print(dna_database)

    # TODO: Read DNA sequence file into a variable
    with open("sequences/1.txt", "r") as file:                           #sys.argv[1]
        dna_Seq = file.read()

    # TODO: Find longest match of each STR in DNA sequence
    



    # TODO: Check database for matching profiles

    return


def longest_match(sequence, subsequence):
    """Returns length of longest run of subsequence in sequence."""

    # Initialize variables
    longest_run = 0
    subsequence_length = len(subsequence)
    sequence_length = len(sequence)

    # Check each character in sequence for most consecutive runs of subsequence
    for i in range(sequence_length):

        # Initialize count of consecutive runs
        count = 0

        # Check for a subsequence match in a "substring" (a subset of characters) within sequence
        # If a match, move substring to next potential match in sequence
        # Continue moving substring and checking for matches until out of consecutive matches
        while True:

            # Adjust substring start and end
            start = i + count * subsequence_length
            end = start + subsequence_length

            # If there is a match in the substring
            if sequence[start:end] == subsequence:
                count += 1

            # If there is no match in the substring
            else:
                break

        # Update most consecutive matches found
        longest_run = max(longest_run, count)

    # After checking for runs at each character in seqeuence, return longest run found
    return longest_run


main()
