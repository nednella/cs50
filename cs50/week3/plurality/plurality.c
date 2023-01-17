#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Max number of candidates
#define MAX 9

// Candidates have name and vote count
typedef struct
{
    string name;
    int votes;
}
candidate;

// Array of candidates
candidate candidates[MAX];

// Number of candidates
int candidate_count;

// Function prototypes
bool vote(string name);
void print_winner(void);





int main(int argc, string argv[])
{
    // Check for invalid usage
    if (argc < 2)
    {
        printf("Usage: plurality [candidate ...]\n");
        return 1;
    }

    // Populate array of candidates via CLI (./plurality X Y Z, where X Y Z are candidate first names)
    candidate_count = argc - 1;
    if (candidate_count > MAX)
    {
        printf("Maximum number of candidates is %i\n", MAX);
        return 2;
    }
    for (int i = 0; i < candidate_count; i++)
    {
        candidates[i].name = argv[i + 1];
        candidates[i].votes = 0;
    }

    // ask user for number of votes participating
    int voter_count = get_int("Number of voters: ");

    // Loop through number of votes participating
    for (int i = 0; i < voter_count; i++)
    {
        // obtain vote from each participant
        string name = get_string("Vote: ");

        // Check for invalid vote
        if (!vote(name))
        {
            printf("Invalid vote.\n");
        }

        else {
            vote(name); // add vote to the count
        }
    }

    // Display winner of election
    print_winner();

}





// Update vote totals given a new vote
bool vote(string name)
{

    // loop through number of candidates
    for (int i = 0; i < candidate_count; i++) {

        // search for a name match e.g. "Ben"
        // if match found
        if (strcmp (name, candidates[i].name)) {

            // update their vote count
            candidates[i].votes ++;
            return true;
        }

        // if match not found
        else {
            // return error
            printf("Error: vote count not updated.\n");
            return false;
        }
    }
    return false;
}





// Print the winner (or winners) of the election
void print_winner(void)
{
    // TODO

    // search vote totals for each candidate

    // pick highest value
    // any candidates with this value
    // printf( winner is candidate(s) )

    return;
}