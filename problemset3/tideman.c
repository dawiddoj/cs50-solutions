#include <cs50.h>
#include <stdio.h>
#include <string.h>

// this program runs an tideman election 

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

// Array of candidates
string candidates[MAX];
pair pairs[MAX * (MAX - 1) / 2];

int pair_count;
int candidate_count;

// Function prototypes
bool vote(int rank, string name, int ranks[]);
void record_preferences(int ranks[]);
void add_pairs(void);
bool has_cycle(int winner, int loser);
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
    for (int i = 0; i < candidate_count; i++)
    {
        if (strcmp(name, candidates[i]) == 0)
        {
            ranks[rank] = i;
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
        for (int j = i + 1; j < candidate_count; j++)
        {
            preferences[ranks[i]][ranks[j]]++; 
        }
    }
    return;
}

// Record pairs of candidates where one is preferred over the other
void add_pairs(void)
{
    for (int r = 0; r < MAX; r++)
    {
        for (int c = r + 1; c < MAX; c++)
        {
            int cani = preferences[r][c];
            int canj = preferences[c][r];
            if (cani != canj)
            {
                pair para;
                if (cani > canj)
                {
                    para.winner = r;
                    para.loser = c;
                }
                else
                {
                    para.winner = c;
                    para.loser = r;
                }
                pairs[pair_count++] = para;
            }
        }
    }
    return;
}

// Sort pairs in decreasing order by strength of victory
void sort_pairs(void)
{
    for (int i = 0; i < pair_count; i++)
    {
        int strength = preferences[pairs[i].winner][pairs[i].loser] - preferences[pairs[i].loser][pairs[i].winner];
        int maxindex = i;
        for (int j = i + 1; j < pair_count; j++)
        {
            int tstrenght = preferences[pairs[j].winner][pairs[j].loser] - preferences[pairs[j].loser][pairs[j].winner];
            if (tstrenght > strength)
            {
                maxindex = j;
                strength = preferences[pairs[j].winner][pairs[j].loser] - preferences[pairs[j].loser][pairs[j].winner];
            }
        }
        pair temporal = pairs[maxindex];
        pairs[maxindex] = pairs[i];
        pairs[i] = temporal;
    }
    return;
}

// check for cycle so locking pairs can be done without any problem
bool has_cycle(int winner, int loser)
{
    while (winner != -1 && winner != loser)
    {
        bool f = false;
        for (int i = 0; i < candidate_count; i++)
        {
            if (locked[i][winner])
            {
                f = true;
                winner = i;
            }
        }
        if (!f)
        {
            winner = -1;
        }
    }
    if (winner == loser)
    {
        return true;
    }
    return false;
}

// Lock pairs into the candidate graph in order, without creating cycles
void lock_pairs(void)
{
    for (int i = 0; i < pair_count; i++)
    {
        if (!has_cycle(pairs[i].winner, pairs[i].loser))
        {
            locked[pairs[i].winner][pairs[i].loser] = true;
        }
    }
    return;
}

// Print the winner of the election
void print_winner(void)
{
    for (int c = 0; c < MAX; c++)
    {
        bool source = true;
        for (int r = 0; r < MAX; r++)
        {
            if (locked[r][c] == true)
            {
                source = false;
                break;
            }
        }
        if (source)
        {
            printf("%s\n", candidates[c]);
            return;
        }
    }
    return;
}

