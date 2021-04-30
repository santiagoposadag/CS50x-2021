#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

// Max number of candidates
#define MAX 9

// preferences[i][j] is number of voters who prefer i over j
int preferences[MAX][MAX];

// locked[i][j] means i is locked in over j
bool locked[MAX][MAX];

// Each pair has a winner, loser
typedef struct
{
    int winner;
    int loser;
}
pair;

//To avoid ccles i created a list of candidates that has and edge pointing towards them.
string pointed_candidates[MAX];

// Array of candidates
string candidates[MAX];
pair pairs[MAX * (MAX - 1) / 2];

int pair_count;
int candidate_count;


// Function prototypes
bool vote(int rank, string name, int ranks[]);
void record_preferences(int ranks[]);
void add_pairs(void);
void sort_pairs(void);
void lock_pairs(void);
void print_winner(void);
int main(int argc, string argv[])
{
    // Check for invalid usage
    if (argc < 2)
    {
        printf("Usage: tideman [candidate ...]\n");
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
        candidates[i] = argv[i + 1];
    }

    // Clear graph of locked in pairs
    for (int i = 0; i < candidate_count; i++)
    {
        for (int j = 0; j < candidate_count; j++)
        {
            locked[i][j] = false;
        }
    }

    pair_count = 0;
    int voter_count = get_int("Number of voters: ");

    // Query for votes
    for (int i = 0; i < voter_count; i++)
    {
        // ranks[i] is voter's ith preference
        int ranks[candidate_count];

        // Query for each rank
        for (int j = 0; j < candidate_count; j++)
        {
            string name = get_string("Rank %i: ", j + 1);

            if (!vote(j, name, ranks))
            {
                printf("Invalid vote.\n");
                return 3;
            }
        }

        record_preferences(ranks);

        printf("\n");
    }



    add_pairs();
    sort_pairs();
    lock_pairs();
    print_winner();
    return 0;
}

// Update ranks given a new vote
bool vote(int rank, string name, int ranks[])
{
    // TODO
    for (int j = 0; j < candidate_count; j++)
    {
        if (strcmp(name, candidates[j]) == 0)
        {
            ranks[rank] = j;
            return true;
        }
    }

    return false;
}

// Update preferences given one voter's ranks
void record_preferences(int ranks[])
{
    for (int i = 0; i < candidate_count; i++)
    {
        for (int j = (i + 1); j < candidate_count; j++)
        {
            preferences[ranks[i]][ranks[j]]++;
        }
    }

    return;
}


// Record pairs of candidates where one is preferred over the other
void add_pairs(void)
{
    // TODO
    for (int i = 0; i < candidate_count; i++)
    {
        for (int j = i; j < candidate_count; j++)
        {
            int value1 = preferences[i][j] - preferences[j][i];
            if (value1 > 0)
            {
                pairs[pair_count].winner = i;
                pairs[pair_count].loser = j;
                pair_count++;
            }
            else if (value1 < 0)
            {
                pairs[pair_count].winner = j;
                pairs[pair_count].loser = i;
                pair_count++;
            }
        }
    }
    return;
}

// Sort pairs in decreasing order by strength of victory
void sort_pairs(void)
{
    // TODO
    //This is going to be a temporary place to save the current winner that we are evaluating and if we need to change it
    int length = (pair_count - 1);
    int organized = 0;
    for (int j = 0; j < pair_count; j++)
    {
        for (int i = length; i > organized ; i--)
        {

            int strength1 = ((int)((preferences[pairs[i].winner][pairs[i].loser]) -
                                   (int)(preferences[pairs[i].loser][pairs[i].winner])));
            int strength2 = ((int)((preferences[pairs[i - 1].winner][pairs[i - 1].loser]) -
                                   (int)(preferences[pairs[i - 1].loser][pairs[i - 1].winner])));

            if (strength1 > strength2)
            {
                int winner1 = pairs[i].winner;
                int loser1 = pairs[i].loser;

                int winner2 = pairs[i - 1].winner;
                int loser2 = pairs[i - 1].loser;

                pairs[i - 1].winner = winner1;
                pairs[i - 1].loser = loser1;

                pairs[i].winner = winner2;
                pairs[i].loser = loser2;
            }
        }
        organized++;
    }
    return;
}

// Lock pairs into the candidate graph in order, without creating cycles
void lock_pairs(void)
{
    // TODO
    printf("Graph just initialized: \n");
    for (int j = 0; j < candidate_count; j++)
    {
        for (int i = 0; i < candidate_count; i++)
        {
            printf("%d| ", locked[j][i]);
        }
        printf("\n");
    }


    for (int i = 0; i < pair_count; i++)
    {
        int winner1 = pairs[i].winner;
        int loser1 = pairs[i].loser;
        int desition = 0;

        for (int j = 0; j < candidate_count; j++)
        {
            bool current1 = locked[j][winner1];

            if (current1 == true)
            {
                int variable = j;
                for (int k = 0; k < candidate_count; k++)
                {
                    if (locked[k][variable] == true && k == loser1)
                    {
                        desition = 1;
                    }
                    else if (locked[k][variable] == true)
                    {
                        variable = k;
                        k = 0;
                    }
                }
            }
        }

        if (desition == 0)
        {
            locked[winner1][loser1] = true;
        }
    }


    printf("Fixed graph: \n");
    for (int j = 0; j < candidate_count; j++)
    {
        for (int i = 0; i < candidate_count; i++)
        {
            printf("%d| ", locked[j][i]);
        }
        printf("\n");
    }

    return;
}

// Print the winner of the election
void print_winner(void)
{
    // TODO
    int results[candidate_count];
    for (int i = 0; i < candidate_count; i++)
    {
        results[i] = 0;
    }

    for (int i = 0; i < candidate_count; i++)
    {
        for (int j = 0; j < candidate_count; j++)
        {
            bool current_lock = locked[j][i];
            if (locked[j][i] == true)
            {
                results[i] = 1;
            }
        }
    }

    for (int i = 0; i < candidate_count; i++)
    {
        int result1 = results[i];
        if (result1 == 0)
        {
            printf("%s\n", candidates[i]);
        }
    }
    return;
}
