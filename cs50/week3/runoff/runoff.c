#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Max voters and candidates
#define MAX_VOTERS 100
#define MAX_CANDIDATES 9

// preferences[i][j] is jth preference for voter i
int preferences[MAX_VOTERS][MAX_CANDIDATES];

// Candidates have name, vote count, eliminated status
typedef struct
{
    string name;
    int votes;
    bool eliminated;
}
candidate;

// Array of candidates
candidate candidates[MAX_CANDIDATES];

// Numbers of voters and candidates
int voter_count;
int candidate_count;

// Function prototypes
bool vote(int voter, int rank, string name);
void tabulate(void);
bool print_winner(void);
int find_min(void);
bool is_tie(int min);
void eliminate(int min);





int main(int argc, string argv[])
{
    // Check for invalid usage
    if (argc < 2)
    {
        printf("Usage: runoff [candidate ...]\n");
        return 1;
    }

    // Populate array of candidates
    candidate_count = argc - 1;
    if (candidate_count > MAX_CANDIDATES)
    {
        printf("Maximum number of candidates is %i\n", MAX_CANDIDATES);
        return 2;
    }
    for (int i = 0; i < candidate_count; i++)
    {
        candidates[i].name = argv[i + 1];
        candidates[i].votes = 0;
        candidates[i].eliminated = false;
    }

    // Populate voter count
    voter_count = get_int("Number of voters: ");
    if (voter_count > MAX_VOTERS)
    {
        printf("Maximum number of voters is %i\n", MAX_VOTERS);
        return 3;
    }

    // query each voter for their votes
    for (int i = 0; i < voter_count; i++)
    {

        // Query for each rank
        for (int j = 0; j < candidate_count; j++)
        {
            string name = get_string("Rank %i: ", j + 1);

            // Record vote, unless it's invalid
            if (!vote(i, j, name))
            {
                printf("Invalid vote.\n");
                return 4;
            }
        }

        printf("\n");
    }












    // Keep holding runoffs until winner exists
    while (true)
    {
        // Calculate votes given remaining candidates
        tabulate();

        // Check if election has been won
        bool won = print_winner();
        if (won)
        {
            break;
        }

        // Eliminate last-place candidates
        int min = find_min();
        bool tie = is_tie(min);

        // If tie, everyone wins
        if (tie)
        {
            for (int i = 0; i < candidate_count; i++)
            {
                if (!candidates[i].eliminated)
                {
                    printf("%s\n", candidates[i].name);
                }
            }
            break;
        }

        // Eliminate anyone with minimum number of votes
        eliminate(min);

        // Reset vote counts back to zero
        for (int i = 0; i < candidate_count; i++)
        {
            candidates[i].votes = 0;
        }
    }
    return 0;
}





// Record preference if vote is valid
bool vote(int voter, int rank, string name)
{
    // TODO
    // iterate through each candidate
    for (int i = 0; i < candidate_count; i++) {

        // check for candidate name matches in the voters preferences
        if (strcmp(candidates[i].name, name) == 0) {

            // if match, record the vote
            preferences[voter][rank] = i;
            return true;
        }
    }
    return false;
}





// Tabulate votes for non-eliminated candidates - done by looping through 2d array and tallying the votes
void tabulate(void)
{
    // TODO
    // iterate through preferences[i][j] matrix and count number of votes
    // iterate through rows, i (voters)
    for (int i = 0; i < voter_count; i++) {

        // iterate through columns, j (candidates)
        for (int j = 0; j < candidate_count; j++) {

            // index the value in the cell
            int index = preferences[i][j];

            // if candidate that matches the value (index) in that cell is not eliminated,
            if (!candidates[index].eliminated) {

                // add vote to their count
                candidates[index].votes ++;
                break;
            }
        }
    }
    return;
}





// Print the winner of the election, if there is one
bool print_winner(void)
{
    // to win the election outright, a given candidate must have more than 50% of the votes
    int min_win = voter_count / 2; // minimum number of votes required to win is equal to 50% of the voter population

    // iterate through each candidate
    for (int i = 0; i < candidate_count; i++) {

        // check for candidate vote tally
        // if candidate votes > 50% of minimum value required to win
        if ( candidates[i].votes > min_win) {

            // printf candidate wins
            printf("%s\n", candidates[i].name);
            return true;
        }
    }
    return false;
}





// Return the minimum number of votes any remaining candidate has
int find_min(void) {

    // initialise value for minimum number of votes to be stored in
    int min = voter_count * candidate_count; // set equal to a value always >= to number max number of votes possible
                                                  // so that the real minimum will never exceed the initialised value

    // iterate through each candidate
    for (int i = 0; i < candidate_count; i++) {

        // if candidate is NOT ELIMINATED
        if (!(candidates[i].eliminated)) {

            // check if their vote tally is less than the current minimum number of votes
            if (candidates[i].votes < min) {

                // if true, overwrite current minimum
                min = candidates[i].votes;
            }
        }
    }

    // if min vote remains unchanged (e.g., no candidates to compare with)
    if (min == voter_count * candidate_count) {

        // return 0
        return 0;
    }

    return min;
}





// Return true if the election is tied between all candidates, false otherwise
bool is_tie(int min)
{
    // TODO
    // iterate through each candidates votes
    for (int i = 0; i < candidate_count; i++) {

        // iterate through the non-eliminated candidates
        if (!candidates[i].eliminated) {

            // if not eliminated
            // check if candidates[i].votes is NOT equal to the minimum number of votes from find_min()
            // e.g., there are candidates remaining in the election who have different numbers of votes to one-another
            if (!(candidates[i].votes == min)) {

                // if false (not equal to the min), return false (no tie)
                return false;
            }
        }
    }

    // if function hasn't already returned false, then it must be true
    return true;
}





// Eliminate the candidate (or candidates) in last place
void eliminate(int min)
{
    // TODO
    // iterate through all candidates
    for (int i = 0; i < candidate_count; i++) {

        // if candidate[i]'s vote tally equals the minimum,
        if (candidates[i].votes == min) {

            // they're in last place, eliminate
            candidates[i].eliminated = true;
        }
    }

    // once all candidates are checked
    return;
}