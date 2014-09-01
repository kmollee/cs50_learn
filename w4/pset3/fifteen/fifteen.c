/**
 * fifteen.c
 *
 * Computer Science 50
 * Problem Set 3
 *
 * Implements the Game of Fifteen (generalized to d x d).
 *
 * Usage: ./fifteen d
 *
 * whereby the board's dimensions are to be d x d,
 * where d must be in [MIN,MAX]
 *
 * Note that usleep is obsolete, but it offers more granularity than
 * sleep and is simpler to use than nanosleep; `man usleep` for more.
 */

#define _XOPEN_SOURCE 500

#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

// board's minimal dimension
#define MIN 3

// board's maximal dimension
#define MAX 9

// board, whereby board[i][j] represents row i and column j
int board[MAX][MAX];

// board's dimension
int d;

// prototypes
void clear(void);
void greet(void);
void init(void);
void draw(void);
bool move(int tile);
bool won(void);
void save(void);
int* get_position(int n);


int main(int argc, string argv[])
{
    // greet player
    greet();

    // ensure proper usage
    if (argc != 2)
    {
        printf("Usage: ./fifteen d\n");
        return 1;
    }

    // ensure valid dimensions
    d = atoi(argv[1]);
    if (d < MIN || d > MAX)
    {
        printf("Board must be between %i x %i and %i x %i, inclusive.\n",
            MIN, MIN, MAX, MAX);
        return 2;
    }

    // initialize the board
    init();

    // accept moves until game is won
    while (true)
    {
        // clear the screen
        clear();

        // draw the current state of the board
        draw();

        // saves the current state of the board (for testing)
        save();

        // check for win
        if (won())
        {
            printf("ftw!\n");
            break;
        }

        // prompt for move
        printf("Tile to move: ");
        int tile = GetInt();

        // move if possible, else report illegality
        if (!move(tile))
        {
            printf("\nIllegal move.\n");
            usleep(500000);
        }

        // sleep for animation's sake
        usleep(500000);
    }

    // that's all folks
    return 0;
}

/**
 * Clears screen using ANSI escape sequences.
 */
void clear(void)
{
    printf("\033[2J");
    printf("\033[%d;%dH", 0, 0);
}

/**
 * Greets player.
 */
void greet(void)
{
    clear();
    printf("GAME OF FIFTEEN\n");
    usleep(2000000);
}

/**
 * Initializes the game's board with tiles numbered 1 through d*d - 1,
 * (i.e., fills board with values but does not actually print them),
 * whereby board[i][j] represents row i and column j.
 */
void init(void)
{

    int tiles = d*d -1;
    // check is odd
    bool isOdd = tiles%2!=0?true:false;
    int tmp = 0;

    for (int row = 0; row < d; row++)
    {
        for (int col = 0; col < d; col++)
        {
            board[row][col] = tiles--;
        }
    }
    // if is odd, swap last two number
    if (isOdd)
    {
        tmp = board[d-1][d-2];
        board[d-1][d-2] = board[d-1][d-3];
        board[d-1][d-3] = tmp;
    }
}

/**
 * Prints the board in its current state.
 */
void draw(void)
{
    for (int row = 0; row < d; row++)
    {
        for (int col = 0; col < d; col++)
        {
            if (board[row][col] == 0)
            {
                printf("  __  ");
            }
            else{
                printf("  %-2d  ", board[row][col]);
            }
        }
        printf("\n");
    }
}

/**
 * If tile borders empty space, moves tile and returns true, else
 * returns false.
 */
bool move(int tile)
{
    if (tile >= d*d)
    {
        return false;
    }
    int tmp = 0;
    int* tile_pos = get_position(tile);
    if (tile_pos == NULL)
    {
        return false;
    }
    int* blank_pos = get_position(0);
    if (blank_pos == NULL)
    {
        return false;
    }
    if (abs(tile_pos[0] - blank_pos[0]) == 1 && tile_pos[1] - blank_pos[1] ==0){
        //swap
        tmp = board[tile_pos[0]][tile_pos[1]];
        board[tile_pos[0]][tile_pos[1]] = board[blank_pos[0]][blank_pos[1]];
        board[blank_pos[0]][blank_pos[1]] = tmp;
        free(tile_pos);
        free(blank_pos);
        return true;
    }
    else if (tile_pos[0] - blank_pos[0] == 0 && abs(tile_pos[1] - blank_pos[1]) ==1){
        //swap
        tmp = board[tile_pos[0]][tile_pos[1]];
        board[tile_pos[0]][tile_pos[1]] = board[blank_pos[0]][blank_pos[1]];
        board[blank_pos[0]][blank_pos[1]] = tmp;
        free(tile_pos);
        free(blank_pos);
        return true;
    }
    else{
        free(tile_pos);
        free(blank_pos);
        return false;
    }
}

/**
 * Returns true if game is won (i.e., board is in winning configuration),
 * else false.
 */
bool won(void)
{
    int tiles = d*d - 1;
    int count = 0;
    int configuration_key = 1;
    for (int row = 0; row < d; row++)
    {
        for (int col = 0; col < d; col++)
        {
            if(board[row][col] == configuration_key){
                    configuration_key++;
                    count ++;
            }
        }
    }
    if (count == tiles)
    {
        return true;
    }
    return false;
}

/**
 * Saves the current state of the board to disk (for testing).
 */
void save(void)
{
    // log
    const string log = "log.txt";

    // delete existing log, if any, before first save
    static bool saved = false;
    if (!saved)
    {
        unlink(log);
        saved = true;
    }

    // open log
    FILE* p = fopen(log, "a");
    if (p == NULL)
    {
        return;
    }

    // log board
    fprintf(p, "{");
    for (int i = 0; i < d; i++)
    {
        fprintf(p, "{");
        for (int j = 0; j < d; j++)
        {
            fprintf(p, "%i", board[i][j]);
            if (j < d - 1)
            {
                fprintf(p, ",");
            }
        }
        fprintf(p, "}");
        if (i < d - 1)
        {
            fprintf(p, ",");
        }
    }
    fprintf(p, "}\n");

    // close log
    fclose(p);
}

int* get_position(int n){
    int* position = malloc(2*sizeof(int));
    for (int row = 0; row < d; row++)
    {
        for (int col = 0; col < d; col++)
        {
            if(board[row][col] == n){
                position[0] = row;
                position[1] = col;
                return position;
            }
        }
    }
    return NULL;
}
