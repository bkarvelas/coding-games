#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 **/

// Data
struct rect_beginning
{
    int W;
    int H;
} rect_beg;

struct rect_ending
{
    int W;
    int H;
} rect_end;

struct general_building
{
    int W;
    int H;
} building;

int N_counter;

void parse_direction(char batman_position[], struct rect_beginning *rect_b, struct rect_ending *rect_e);
int binary_search_2d(int beginning, int end, char direction);

int main()
{
    // width, height of the building.
    scanf("%d%d", &building.W, &building.H);

    // maximum number of turns before game over.
    int N;
    scanf("%d", &N);

    N_counter = N;

    // Batman Position
    int x_bat_pos, y_bat_pos;
    scanf("%d%d", &x_bat_pos, &y_bat_pos);

    // game loop
    while (1)
    {
        // the direction of the bombs from batman's current location (U, UR, R, DR, D, DL, L or UL)
        char bomb_dir[4];
        scanf("%s", bomb_dir);

        // Write an action using printf(). DON'T FORGET THE TRAILING \n
        // To debug: fprintf(stderr, "Debug messages...\n");
        fprintf(stderr, "W: %d | H: %d\n", building.W, building.H);
        fprintf(stderr, "Jumps: %d \n", N);
        fprintf(stderr, "Batman Location (%d,%d) \n", x_bat_pos, y_bat_pos);
        fprintf(stderr, "Bomb Location %s \n", bomb_dir);

        // the location of the next window Batman should jump to.
        // printf("3 7\n");
        N_counter--;
    }

    return 0;
}

void parse_direction(char batman_position[], struct rect_beginning *rect_b, struct rect_ending *rect_e)
{
    // y_bat_b, x_bat_b is the begining of the search rectangle area (y_bat_pos + 1, x_bat_pos + 1)
    int i = 0, y_bat_b = 0, x_bat_b = 0;
    while (batman_position[i] != '\0')
    {
        // Initial batman position, direction

        // U D L R
        switch (batman_position[i])
        {
            // ama einai Up vres to akrivws Up tetragwno mexri telous
        case 'U':

            // if dir = U
            //      if N == N_Counter // if it is the first move
            //          bs_beg = rect_beg.H = 0
            //      else
            //          bs_beg = rect_beg.H = prev_y_bat_pos
            // bs_end = rect_end.H = y_bat_pos
            break;

            // ama einai Down vres to akrivws Down tetragwno mexri telous
        case 'D':
            // if dir = D
            // bs_beg = rect_beg.H = y_bat_pos
            //      if N == N_Counter // if it is the first move
            //          bs_end = rect_beg.H = building.H - 1
            //      else
            //          if prev_y_bat_pos > y_bat_pos
            //              bs_end = rect_beg.H = prev_y_bat_pos
            break;

            // ama einai Left vres to akrivws Left tetragwno mexri telous
        case 'L':
            // if dir = L
            //      if N == N_Counter // if it is the first move
            //
            // bs_beg = rect_beg.W = 0
            // bs_end = rect_end.W = x_bat_pos
            break;

            // ama einai Right vres to akrivws Right tetragwno mexri telous
        case 'R':
            // if dir = R
            // bs_beg = rect_beg.W = x_bat_pos
            // bs_end = rect_end.W = W - 1
            break;

        default:
            break;
        }
    }
}

int binary_search_2d(int beginning, int end, char direction)
{
    if (end >= beginning)
    {
        int mid = beginning + (end - beginning) / 2;

        // If element is smaller than mid, then
        // it can only be present in left subarray
        if (direction == 'L' || direction == 'U')
            return mid - 1;

        // Else the element can only be present
        // in right subarray
        return mid + 1;
    }

    // We reach here when element is not
    // present in array
    return -1;
}