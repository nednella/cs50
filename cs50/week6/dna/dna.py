import csv
import sys


def main():

    # TODO: Check for command-line usage
    #if len(sys.argv) != 3:
        #sys.exit("USAGE: python dna.py [data.csv] [sequence.txt]")

    # TODO: Read database file into a variable
    dna_Database = []

    with open("databases/small.csv", "r") as csv_file:              #sys.argv[1]
        db_reader = csv.DictReader(csv_file)
        for row in db_reader:
            dna_Database.append(row)


    # TODO: Read DNA sequence file into a variable
    with open("sequences/1.txt", "r") as txt_file:                  #sys.argv[1]
        dna_Sequence = txt_file.read()

    # TODO: Find longest match of each STR in DNA sequence
    results = {}

    subSeqs = list(dna_Database[0].keys())[1:]

    for subSeq in subSeqs:
        results[subSeq] = longest_match(dna_Sequence, subSeq)

    # TODO: Check database for matching profiles
    perf_Match = len(subSeqs)                               # all STRs must match for DNA to be identified
    match = 0                                               # initialise match counter

    for person in dna_Database:                             # iterate through every row in the DNA database
        for subSeq in subSeqs:                                  # iterate through every STR in the list of STRs

            if int(person[subSeq]) == results[subSeq]:              # if match, + 1 to counter
                match += 1

        if match == perf_Match:                                 # if perfect match, print person and exit program
            sys.exit(f"Match Found: {person['name']}")
        else:                                                   # else, reset match counter for next person and continue
            match = 0
            continue

    sys.exit("No Match Found.")





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
