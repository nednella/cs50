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

    // Loop over all voters
    for (int i = 0; i < voter_count; i++)
    {
        string name = get_string("Vote: ");

        // Check for invalid vote - this will perform the function 'vote' on the supplied name
        // if true, no prompt will be given, but the vote will STILL BE LOGGED
        // if false, an error prompt will be given
        if (!vote(name))
        {
            printf("Invalid vote.\n");
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
        if (strcmp (candidates[i].name, name) == 0) {

            // update their vote count
            candidates[i].votes++;
            return true;
        }
    }
    return false;
}





// Print the winner (or winners) of the election
void print_winner(void) {

    // initialise the highest vote
    int highest_vote = 0;

    // loop through stored votes
    for (int i = 0; i < candidate_count; i++) {

        // if candidate[i]'s vote score is higher than the highest vote,
        if (candidates[i].votes > highest_vote) {

            // update the value of highest_vote
            highest_vote = candidates[i].votes;
        }
    }

    // loop through the stored candidates
    for (int i = 0; i < candidate_count; i++) {

        // printf the names of the candidates who's votes match the highest vote (allows for multiple in case of tie)
        if (candidates[i].votes == highest_vote) {

            printf("%s\n", candidates[i].name);
        }
    }
    return;
}