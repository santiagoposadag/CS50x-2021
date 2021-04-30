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

    // Populate array of candidates
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

    int voter_count = get_int("Number of voters: ");

    // Loop over all voters
    for (int i = 0; i < voter_count; i++)
    {
        string name = get_string("Vote: ");

        // Check for invalid vote
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
    // TODO
    for (int i = 0; i < candidate_count; i++)
    {
        if (strcmp(name, candidates[i].name) == 0)
        {
            candidates[i].votes++;
            return true;
        }
    }
    return false;
}

// Print the winner (or winners) of the election
void print_winner(void)
{
    // TODO
    //here we are going to store the first winner and the compare if there is any other candidate with the same amount
    //of votes stored in score.
    if (candidate_count == 1)
    {
        printf("%s", candidates[0].name);
        return;
    }


    string first_winner = candidates[0].name;
    int score = candidates[0].votes;

    for (int i = 0; i < candidate_count; i++)
    {
        if (score < candidates[i].votes)
        {
            first_winner = candidates[i].name;
            score = candidates[i].votes;
        }
    }
    printf("%s\n", first_winner);

    for (int i = 0; i < candidate_count; i++)
    {
        if (strcmp(candidates[i].name, first_winner) != 0)
        {
            if (candidates[i].votes == score)
            {
                printf("%s\n", candidates[i].name);
            }
        }
    }

    return;
}

