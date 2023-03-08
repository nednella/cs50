import csv
import sys


def main():

    # TODO: Check for command-line usage
    #if len(sys.argv) != 3:
        #sys.exit("USAGE: python dna.py [data.csv] [sequence.txt]")



    # TODO: Read database file into a variable
    dna_Database = []

    with open("databases/small.csv", "r") as file:                          #sys.argv[1]
        db_reader = csv.DictReader(file)
        for row in db_reader:
            tmp_name = row['name']
            tmp_agatc = int(row['AGATC'])
            tmp_aatg = int(row['AATG'])
            tmp_tatc = int(row['TATC'])
            dna_Database.append({'Name': tmp_name, 'AGATC': tmp_agatc, 'AATG': tmp_aatg, 'TATC': tmp_tatc})

    #print(dna_database)

    # TODO: Read DNA sequence file into a variable
    with open("sequences/1.txt", "r") as file:                              #sys.argv[1]
        dna_Sequence = file.read()

    # TODO: Find longest match of each STR in DNA sequence
    dna_Sample = []

    agatc = int(dna_Sequence.count('AGATC'))                                # find DNA STR match from dna sequence .txt file
    dna_Sample.append(agatc)                                                # append to list

    aatg = int(dna_Sequence.count('AATG'))
    dna_Sample.append(aatg)

    tatc = int(dna_Sequence.count('TATC'))
    dna_Sample.append(tatc)

    #print(dna_Sample)

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
